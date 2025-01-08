#pragma once

#include "Scene.h"


namespace hs
{
	class GrindingScene : public Scene
	{
	public:
		GrindingScene(uint8_t monsterCnt, uint8_t monsterGenPeriod, std::vector<Monster> monsters);
		~GrindingScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC& hdc) override;

	private:
		uint8_t mMonsterCount;
		uint8_t mMonsterGenPeriod;
		std::vector<Monster> mMonsters;
		// Geometry;
	};
}