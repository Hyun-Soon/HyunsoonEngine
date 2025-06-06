#pragma once

#include <unordered_map>
#include <bitset>

#include "Component/BoxCollider2D.h"
#include "Component/CircleCollider2D.h"
#include "CollisionMap.h"

namespace hs
{
	using namespace enums;

	union CollisionID
	{
		struct
		{
			UINT32 left;
			UINT32 right;
		};

		UINT64 id;
	};

	class CollisionManager
	{
	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC& hdc);

		static void CollisionLayerCheck(eLayerType left, eLayerType right, bool enable);
		static void LayerCollision(class Scene* scene, eLayerType left, eLayerType right);
		static void CheckColliderCollisions(std::vector<Collider*> lefts, std::vector<Collider*> rights);
		static void ColliderCollision(Collider* left, Collider* right);
		static bool Intersect(Collider* left, Collider* right);
		static void CreateCollisionMap(std::wstring name);
		static bool CheckCollisionMap(Vector2 pos, const Vector2& size);

		static CollisionMap* GetActiveCollisionMap();
		static const Vector2 GetPossiblePos(Vector2 pos, const Vector2& dir, const Vector2& size);

	private:
		static void findCollidersRecur(GameObject* obj, std::vector<Collider*>& colliderVec);

		static std::bitset<(UINT)eLayerType::BitsetSize>	   mCollisionLayerMatrix[(UINT)eLayerType::BitsetSize];
		static std::unordered_map<UINT64, bool>				   mCollisionHistory;
		static std::unordered_map<std::wstring, CollisionMap*> mCollisionMaps;
	};
} // namespace hs
