#pragma once

namespace hs
{
	namespace enums
	{
		enum class eComponentType
		{
			Transform,
			Rigidbody,
			SpriteRenderer,
			Camera,
			Animator,
			Script,
			End,
		};

		enum class eLayerType
		{
			Background,
			Monster,
			Player,
			Item,
			Npc,
			Particle,
			End,
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