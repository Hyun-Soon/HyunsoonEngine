#pragma once

#include "../../../HyunsoonEngine_CommonSources/Scene/Scene.h"

namespace hs
{
	class BeginnersTown2 : public Scene
	{
	public:
		BeginnersTown2();
		~BeginnersTown2();

		virtual void Initialize() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
	};

} // namespace hs
