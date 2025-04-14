#pragma once

#include "../../HyunsoonEngine_CommonSources/Scene/Scene.h"

namespace hs
{
	class ZakumRoad : public Scene
	{
	public:
		ZakumRoad();
		~ZakumRoad();

		virtual void Initialize() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
	};

} // namespace hs
