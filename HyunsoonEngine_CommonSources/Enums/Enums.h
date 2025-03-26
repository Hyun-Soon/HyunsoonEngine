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
			// None,
			Background,
			Monster,
			Player,
			Item,
			Npc,
			Particle,
			End,
			BitsetSize = 8,
		};

		enum class eResourceType
		{
			Texture,
			AudioClip,
			Prefab,
			Animation,
			End,
		};
	} // namespace enums
} // namespace hs