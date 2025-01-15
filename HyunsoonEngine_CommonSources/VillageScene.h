#pragma once

#include "Scene.h"
#include "Npc.h"

namespace hs
{
	class VillageScene : public Scene
	{
	public:
		VillageScene();
		~VillageScene();

		virtual void Initialize() override;

	private:
		// background image
	};
} // namespace hs