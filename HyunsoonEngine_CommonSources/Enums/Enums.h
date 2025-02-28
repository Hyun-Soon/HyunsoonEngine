#pragma once

namespace hs
{
	namespace enums
	{
		enum class eComponentType
		{
			Transform,
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