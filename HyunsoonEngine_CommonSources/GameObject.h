#pragma once

#include "Input.h"

namespace hs
{
	class GameObject
	{
	public:
		struct Position
		{
			float x;
			float y;

			Position(float x, float y) : x(x), y(y) {}
		};

		GameObject();
		~GameObject();

		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC& hdc);

		void SetPosition(float x, float y);

		const float GetPositionX() const;
		const float GetPositionY() const;

	protected:
		float mSpeed;
		Position mPos;

	private:
		void repositionWithinBounds();


	};
}