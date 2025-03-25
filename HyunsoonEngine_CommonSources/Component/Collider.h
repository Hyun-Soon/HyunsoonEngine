#pragma once

#include "MathTypes.h"
#include "Component.h"

namespace hs
{
	class Collider : public Component
	{
	public:
		Collider();
		~Collider();

		virtual void Initialize() = 0;
		virtual void Update() = 0;
		virtual void LateUpdate() = 0;
		virtual void Render(HDC& hdc) = 0;

		Vector2 GetOffset() const { return mOffset; }
		void	SetOffset(Vector2 offset) { mOffset = offset; }

	private:
		Vector2 mOffset;
	};
} // namespace hs
