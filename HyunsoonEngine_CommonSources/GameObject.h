#pragma once

#include "Input.h"

namespace hs
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC& hdc);

		void SetPosition(float x, float y);

		const float GetPositionX() const;
		const float GetPositionY() const;

	private:
		float mX;
		float mY;
	};
}