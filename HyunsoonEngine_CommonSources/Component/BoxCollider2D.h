#pragma once

#include "MathTypes.h"
#include "Collider.h"

namespace hs
{
	class BoxCollider2D : public Collider
	{
	public:
		BoxCollider2D();
		~BoxCollider2D();

		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC& hdc) override;

	private:
	};
} // namespace hs