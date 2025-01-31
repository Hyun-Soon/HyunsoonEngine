#pragma once

namespace hs
{
	namespace enums
	{
		enum class eComponentType
		{
			Transform,
			SpriteRenderer,
			Physics,
			Script,
			Camera,
			End,
		};

		enum class eLayerType
		{
			Background,
			Monster,
			Player,
			Item,
			Npc,
			End,
		};

		enum class eResourceType
		{
			Texture,
			AudioClip,
			Prefab,
			End,
		};
	} // namespace enums
} // namespace hs