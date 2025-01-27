#pragma once

#include "Scene/Scene.h"

namespace hs
{
	class BeginnersTown1 : public Scene
	{
	public:
		BeginnersTown1();
		~BeginnersTown1();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC& hdc) override;

	private:
	};

} // namespace hs
