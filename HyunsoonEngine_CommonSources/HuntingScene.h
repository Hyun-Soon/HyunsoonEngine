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

	private:
		uint8_t mMonsterGenPeriod;
		// Geometry;
	};
} // namespace hs