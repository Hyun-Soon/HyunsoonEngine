#pragma once

#include "../../HyunsoonEngine_CommonSources/Scene/Scene.h"

namespace hs
{
	class AlterOfZakum : public Scene
	{
	public:
		AlterOfZakum();
		~AlterOfZakum();

		virtual void Initialize() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
	};

} // namespace hs
