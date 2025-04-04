#pragma once

#include "Collider.h"

namespace hs
{
	class CircleCollider2D : public Collider
	{
	public:
		CircleCollider2D();
		~CircleCollider2D();

		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC& hdc) override;

	private:
		float mRadius;
	};
} // namespace hs
