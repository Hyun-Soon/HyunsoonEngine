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
		Vector2 CalculateRatioPosition(Vector2 pos, Vector2 res);

		Camera();
		~Camera();

		void Initialize() override;
		void Update() override;

		void SetTarget(GameObject* target) { mTarget = target; };

	private:
		GameObject* mTarget;
		Vector2		mDistance;
		Vector2		mResolution;
		Vector2		mLookPosition;
		Vector2		mRatio;
	};
} // namespace hs
