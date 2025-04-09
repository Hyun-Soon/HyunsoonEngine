#pragma once

namespace hs
{
	namespace enums
	{
		enum class eComponentType
		{
			Transform,
			Collider,
			SpriteRenderer,
			Camera,
			Animator,
			Script,
			Rigidbody,
			End,
		};

		enum class eLayerType
		{
			Background,
			Monster,
			Player,
			Item,
			Projectile,
			Npc,
			Particle,
			End,
			BitsetSize = 16,
			None,
		};

		enum class eResourceType
		{
			Texture,
			AudioClip,
			Prefab,
			Animation,
			End,
		};

		enum class eColliderType
		{
			Circle2D,
			Rect2D,
			End,
		};

		enum class eUIType
		{
			BottomBar,
			Button,
			Inventory,
			End,
		};
	} // namespace enums
} // namespace hs