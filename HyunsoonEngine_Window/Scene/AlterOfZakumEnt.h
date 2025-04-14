#pragma once

#include "../../HyunsoonEngine_CommonSources/Scene/Scene.h"

namespace hs
{
	class AlterOfZakumEnt : public Scene
	{
	public:
		AlterOfZakumEnt();
		~AlterOfZakumEnt();

		virtual void Initialize() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
	};

} // namespace hs
