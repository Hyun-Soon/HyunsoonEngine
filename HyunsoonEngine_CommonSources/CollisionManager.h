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
		static void ColliderCollision(Collider* left, Collider* right);
		static bool Intersect(Collider* left, Collider* right);
		static void CreateCollisionMap(std::wstring name);
		static bool CheckCollisionMap(Vector2 pos);

		static CollisionMap* GetActiveCollisionMap();
		static const Vector2 GetGroundPos(Vector2 pos);

	private:
		static std::bitset<(UINT)eLayerType::BitsetSize>	   mCollisionLayerMatrix[(UINT)eLayerType::BitsetSize];
		static std::unordered_map<UINT64, bool>				   mCollisionHistory;
		static std::unordered_map<std::wstring, CollisionMap*> mCollisionMaps;
	};
} // namespace hs
