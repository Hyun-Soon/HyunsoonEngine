#include <algorithm>

#include "CollisionManager.h"
#include "Scene/Scene.h"
#include "Scene/SceneManager.h"
#include "GameObject/GameObject.h"
#include "Component/Collider.h"
#include "Component/Transform.h"

namespace hs
{
	std::bitset<(UINT)eLayerType::BitsetSize>		CollisionManager::mCollisionLayerMatrix[(UINT)eLayerType::BitsetSize] = {};
	std::unordered_map<UINT64, bool>				CollisionManager::mCollisionHistory = {};
	std::unordered_map<std::wstring, CollisionMap*> CollisionManager::mCollisionMaps = {};

	void CollisionManager::Initialize()
	{
		CollisionManager::CollisionLayerCheck(enums::eLayerType::Player, enums::eLayerType::Monster, true);
		CollisionManager::CollisionLayerCheck(enums::eLayerType::Monster, enums::eLayerType::Projectile, true);
	}

	void CollisionManager::Update()
	{
		Scene* scene = SceneManager::GetActiveScene();
		for (UINT row = 0; row < (UINT)eLayerType::End; row++)
		{
			for (UINT col = 0; col <= row; col++)
			{
				if (mCollisionLayerMatrix[row][col] == true)
				{
					LayerCollision(scene, (eLayerType)row, (eLayerType)col);
				}
			}
		}
	}

	void CollisionManager::LateUpdate()
	{
	}

	void CollisionManager::Render(HDC& hdc)
	{
		CollisionMap* colMap = GetActiveCollisionMap();

		for (int i = 0; i < colMap->GetResolution().y; i++)
		{
			for (int j = 0; j < colMap->GetResolution().x; j++)
			{
				if (colMap->collisionData[i * colMap->GetResolution().x + j])
					SetPixel(hdc, j, i, RGB(255, 0, 0));
			}
		}
	}

	void CollisionManager::CollisionLayerCheck(eLayerType leftType, eLayerType rightType, bool enable)
	{
		int row = 0;
		int col = 0;

		if (leftType >= rightType)
		{
			row = (UINT)leftType;
			col = (UINT)rightType;
		}
		else
		{
			row = (UINT)rightType;
			col = (UINT)leftType;
		}

		mCollisionLayerMatrix[row][col] = enable;
	}

	void CollisionManager::LayerCollision(Scene* scene, eLayerType leftType, eLayerType rightType) // not means literally leftside and rightside. just seperate two objects.
	{
		const std::vector<GameObject*>& lefts = scene->GetLayer(leftType)->GetGameObjects();
		const std::vector<GameObject*>& rights = scene->GetLayer(rightType)->GetGameObjects();

		for (GameObject* left : lefts)
		{
			if (left->IsActive() == false)
				continue;
			Collider* leftCollider = left->GetComponent<Collider>();
			if (leftCollider == nullptr)
				continue;

			for (GameObject* right : rights)
			{
				if (right->IsActive() == false)
					continue;
				Collider* rightCollider = right->GetComponent<Collider>();
				if (rightCollider == nullptr)
					continue;
				if (left == right)
					continue;

				ColliderCollision(leftCollider, rightCollider);
			}
		}
	}

	void CollisionManager::ColliderCollision(Collider* leftCollider, Collider* rightCollider)
	{
		// 두 충돌체 번호로 가져온 ID 확인하여 CollisionID 세팅
		CollisionID id = {};
		id.left = leftCollider->GetID();
		id.right = rightCollider->GetID();

		std::unordered_map<UINT64, bool>::iterator iter = mCollisionHistory.find(id.id);
		if (iter == mCollisionHistory.end())
		{
			mCollisionHistory.insert(std::make_pair(id.id, false));
			iter = mCollisionHistory.find(id.id);
		}

		if (Intersect(leftCollider, rightCollider))
		{
			if (iter->second == false)
			{
				leftCollider->OnCollisionEnter(rightCollider);
				rightCollider->OnCollisionEnter(leftCollider);
				iter->second = true;
			}
			else
			{
				leftCollider->OnCollisionStay(rightCollider);
				rightCollider->OnCollisionStay(leftCollider);
			}
		}
		else
		{
			if (iter->second == true)
			{
				leftCollider->OnCollisionExit(rightCollider);
				rightCollider->OnCollisionExit(leftCollider);

				iter->second = false;
			}
		}
	}

	bool CollisionManager::Intersect(Collider* left, Collider* right)
	{
		Transform* leftTr = left->GetOwner()->GetComponent<Transform>();
		Transform* rightTr = right->GetOwner()->GetComponent<Transform>();

		Vector2 leftPos = leftTr->GetCenterPosition() + left->GetOffset();
		Vector2 rightPos = rightTr->GetCenterPosition() + right->GetOffset();

		Vector2 leftSize = left->GetSize();
		Vector2 rightSize = right->GetSize();

		// AABB 충돌
		enums::eColliderType leftType = left->GetColliderType();
		enums::eColliderType rightType = right->GetColliderType();

		if (leftType == enums::eColliderType::Rect2D
			&& rightType == enums::eColliderType::Rect2D)
		{
			if (fabs(leftPos.x - rightPos.x) < fabs((leftSize.x + rightSize.x) / 2.0f)
				&& fabs(leftPos.y - rightPos.y) < fabs((leftSize.y + rightSize.y) / 2.0f))
			{
				return true;
			}
		}

		if (leftType == enums::eColliderType::Circle2D
			&& rightType == enums::eColliderType::Circle2D)
		{
			// circle -circle
			Vector2 leftCirclePos = leftPos - (leftSize / 2.0f);
			Vector2 rightCirclePos = rightPos - (rightSize / 2.0f);
			float	distance = (leftCirclePos - rightCirclePos).Length();
			if (distance <= ((leftSize.x + rightSize.x) / 2.0f))
			{
				return true;
			}
		}

		if ((leftType == enums::eColliderType::Circle2D && rightType == enums::eColliderType::Rect2D)
			|| (leftType == enums::eColliderType::Rect2D && rightType == enums::eColliderType::Circle2D))
		{
			// circle - rect
			Collider* circle = (leftType == enums::eColliderType::Circle2D) ? left : right;
			Collider* rect = (leftType == enums::eColliderType::Rect2D) ? left : right;

			Vector2 circlePos = (circle == left) ? leftPos : rightPos;
			Vector2 rectPos = (rect == left) ? leftPos : rightPos;
			Vector2 rectSize = (rect == left) ? leftSize : rightSize;
			float	circleRadius = (circle == left) ? leftSize.x / 2.0f : rightSize.x / 2.0f;

			// 사각형의 절반 크기
			Vector2 halfRectSize = rectSize / 2.0f;

			// 사각형의 중심 좌표
			Vector2 rectCenter = rectPos;

			// 원의 중심에서 가장 가까운 사각형의 점 찾기
			float closestX = std::fmax(rectCenter.x - halfRectSize.x, std::fmin(circlePos.x, rectCenter.x + halfRectSize.x));
			float closestY = std::fmax(rectCenter.y - halfRectSize.y, std::fmin(circlePos.y, rectCenter.y + halfRectSize.y));

			// 원의 중심과 가장 가까운 점 사이의 거리 계산
			Vector2 closestPoint(closestX, closestY);
			float	distance = (circlePos - closestPoint).Length();

			// 꼭짓점이 아닌, 변과의 충돌 체크 필요

			// 충돌 여부 확인
			if (distance <= circleRadius)
			{
				return true;
			}
		}

		return false;
	}

	void CollisionManager::CreateCollisionMap(std::wstring name)
	{
		mCollisionMaps.insert(std::pair<std::wstring, CollisionMap*>(name, new CollisionMap(name)));
	}

	bool CollisionManager::CheckCollisionMap(Vector2 pos)
	{
		std::wstring sceneName = SceneManager::GetActiveScene()->GetName();
		auto		 colMapIter = mCollisionMaps.find(sceneName);
		if (colMapIter == mCollisionMaps.end())
			return false;
		CollisionMap* colMap = colMapIter->second;
		return colMap->CheckCollision(pos);
	}

	CollisionMap* CollisionManager::GetActiveCollisionMap()
	{
		return mCollisionMaps[SceneManager::GetActiveScene()->GetName()];
	}

	const Vector2 CollisionManager::GetGroundPos(Vector2 pos)
	{
		CollisionMap* curMap = GetActiveCollisionMap();

		while (curMap->CheckCollision(pos))
		{
			--pos.y;
		}

		//int			  width = curMap->GetResolution().x;

		//int idx = (int)pos.y * width + (int)pos.x;
		//while (curMap->collisionData[idx] && pos.y > 0)
		//{
		//	--pos.y;
		//	idx = pos.y * width + pos.x;
		//}

		return pos;
	}
} // namespace hs
