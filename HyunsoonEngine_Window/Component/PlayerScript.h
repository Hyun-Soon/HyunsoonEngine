#pragma once

#include <random>

#include "Component/Animator.h"
#include "Component/Transform.h"
#include "Component/Rigidbody.h"

namespace hs
{
	class PlayerScript : public Component
	{
	public:
		PlayerScript();
		~PlayerScript();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		// virtual void Render(HDC& hdc) override;

		// void SetAnimator(Animator* animator);

	private:
		std::wstring getRandomValueString(int minVal, int maxVal);

		void stand();
		void walk();
		void alert();
		void jump();
		void doubleJump();
		void attack();
		void lieDown();

		Player*		 mPlayer;
		Transform*	 mTransform;
		Rigidbody*	 mRigidbody;
		Animator*	 mAnimator;
		Vector2		 mDirection;
		float		 mDuration;
		std::wstring mDirString;
	};

} // namespace hs