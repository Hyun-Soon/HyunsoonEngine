#pragma once

#include "Scene/Scene.h"

namespace hs
{
	class HuntingScene : public Scene
	{
	public:
		HuntingScene();
		~HuntingScene();

		void Initialize() override;

		// Monster* FindNearestMonster(float range);

	private:
		uint8_t mMonsterGenPeriod;
		// std::vector<Monster*> mMonsters;
		//  Geometry;
	};
} // namespace hs