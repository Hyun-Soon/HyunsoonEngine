#include "CollisionManager.h"
#include "Scene/Scene.h"
#include "Scene/SceneManager.h"
#include "GameObject/GameObject.h"
#include "Component/Collider.h"
#include "Component/Transform.h"

namespace hs
{

	std::bitset<(UINT)eLayerType::BitsetSize> CollisionManager::mCollisionLayerMatrix[(UINT)eLayerType::BitsetSize] = {};
	std::unordered_map<UINT64, bool>		  CollisionManager::mCollisionMap = {};

	void CollisionManager::Initialize()
	{
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

	void CollisionManager::Render(HDC hdc)
	{
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

		std::unordered_map<UINT64, bool>::iterator iter = mCollisionMap.find(id.id);
		if (iter == mCollisionMap.end())
		{
			mCollisionMap.insert(std::make_pair(id.id, false));
			iter = mCollisionMap.find(id.id);
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

		Vector2 leftPos = leftTr->GetPosition() + left->GetOffset();
		Vector2 rightPos = rightTr->GetPosition() + right->GetOffset();

		// size 1,1 일떄 기본크기가 100픽셀
		Vector2 leftSize = left->GetSize() * 100.0f;
		Vector2 rightSize = right->GetSize() * 100.0f;

		// AABB 충돌
		if (fabs(leftPos.x - rightPos.x) < fabs((leftSize.x + rightSize.x) / 2.0f)
			&& fabs(leftPos.y - rightPos.y) < fabs((leftSize.y + rightSize.y) / 2.0f))
		{
			return true;
		}

		return false;
	}

} // namespace hs
