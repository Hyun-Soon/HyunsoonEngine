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

		void Update();
		void LateUpdate();
		void Render(HDC& hdc);

		void SetPosition(float x, float y);

		const float GetPositionX() const;
		const float GetPositionY() const;

	private:
		Position mPos;
		float mSpeed;
	};
}