#pragma once

#include "Input.h"
#include "PhysicsTypes.h"

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

		const float GetPositionX() const;
		const float GetPositionY() const;

	protected:
		Position mPos;

	private:
		void repositionWithinBounds();


	};
}