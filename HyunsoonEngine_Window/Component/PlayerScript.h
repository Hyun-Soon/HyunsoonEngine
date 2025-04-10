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
		virtual void Render(HDC& hdc) override;

		// void SetAnimator(Animator* animator);

		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;

		const Vector2& GetDirection() const { return mDirection; }

	private:
		void resetDuration() { mDuration = 0.0f; }
		void translateToIdle();
		void translateToMove(eKeyCode keyCode);
		void translateToAlert();
		void translateToJump();
		void translateToDoubleJump();
		void translateToAttack();
		void translateToLyingDown();

		void idle();
		void move();
		void alert();
		void jump();
		void doubleJump();
		void attack();
		void lieDown();

		Player*	   mPlayer;
		Transform* mTransform;
		Rigidbody* mRigidbody;
		Animator*  mAnimator;
		Vector2	   mDirection;
		float	   mDuration;
		float	   mSpeed;

		Vector2 mJumpVel;
		Vector2 mDoubleJumpSpeed;
	};

} // namespace hs