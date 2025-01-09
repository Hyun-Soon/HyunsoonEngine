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
		//virtual void Update() override;
		//virtual void LateUpdate() override;
		//virtual void Render(HDC& hdc) override;

	private:
		//background image
	};
}