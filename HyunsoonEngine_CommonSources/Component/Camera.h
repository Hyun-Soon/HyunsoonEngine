#pragma once

#include "Component/Component.h"
#include "MathTypes.h"

namespace hs
{
	class GameObject;
	class Camera : public Component
	{
	public:
		Vector2 CalculatePosition(Vector2 pos) { return pos - mDistance; };

		Camera();
		~Camera();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC& hdc) override;

	private:
		GameObject* mTarget;
		Vector2		mDistance;
		Vector2		mResolution;
		Vector2		mLookPosition;
	};
} // namespace hs
