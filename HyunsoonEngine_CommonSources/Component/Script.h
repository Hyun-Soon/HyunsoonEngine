#pragma once

#include "Component.h"

namespace hs
{
	class Collider;

	class Script : public Component
	{
	public:
		Script();
		~Script();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC& hdc) override;

		virtual void OnCollisionEnter(Collider* other) = 0;
		virtual void OnCollisionStay(Collider* other) = 0;
		virtual void OnCollisionExit(Collider* other) = 0;

	private:
	};
} // namespace hs
