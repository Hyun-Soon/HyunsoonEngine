#pragma once

#include "Component/Animator.h"
#include "Component/Transform.h"
#include "Component/Rigidbody.h"
#include "Component/Script.h"

#include "../Object/Player.h";

namespace hs
{
	class Player;
	class PlayerScript : public Script
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
		float		 mSpeed;
		std::wstring mDirString;

		Vector2 mJumpForce;
		Vector2 mDoubleJumpSpeed;
	};

} // namespace hs