#pragma once

#include "../../HyunsoonEngine_CommonSources/Scene/Scene.h"

namespace hs
{
	class CrossRoad : public Scene
	{
	public:
		CrossRoad();
		~CrossRoad();

		virtual void Initialize() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
	};

} // namespace hs