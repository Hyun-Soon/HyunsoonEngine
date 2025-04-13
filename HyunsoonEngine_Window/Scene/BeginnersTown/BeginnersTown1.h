#pragma once

#include "../../../HyunsoonEngine_CommonSources/Scene/Scene.h"

namespace hs
{
	class BeginnersTown1 : public Scene
	{
	public:
		BeginnersTown1();
		~BeginnersTown1();

		virtual void Initialize() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
	};

} // namespace hs
