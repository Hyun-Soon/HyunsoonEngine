#pragma once

#include "../../HyunsoonEngine_CommonSources/Scene/Scene.h"

namespace hs
{
	class KerningCity : public Scene
	{
	public:
		KerningCity();
		~KerningCity();

		virtual void Initialize() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
	};

} // namespace hs
