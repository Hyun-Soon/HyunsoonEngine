#pragma once

#include "Scene.h"


namespace hs
{
	class HuntingScene : public Scene
	{
	public:
		HuntingScene();
		~HuntingScene();

		virtual void Initialize() override;
		//virtual void Update() override;
		//virtual void LateUpdate() override;
		//virtual void Render(HDC& hdc) override;

	private:
		uint8_t mMonsterGenPeriod;
		// Geometry;
	};
}