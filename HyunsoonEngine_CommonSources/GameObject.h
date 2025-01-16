#pragma once

#include "Input.h"
#include "MathTypes.h"

namespace hs
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC& hdc);

		void SetPosition(float x, float y);

		const Vector2& GetPosition() const;

	protected:
		Vector2 mPos;

	private:
		void repositionWithinBounds();
	};
} // namespace hs