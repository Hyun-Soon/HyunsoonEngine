#pragma once

#include "Component/Animator.h"
#include "Component/Transform.h"
#include "Component/Rigidbody.h"
#include "Component/Script.h"

#include "../Object/Monster.h"

namespace hs
{
	class JrBalrogScript : public Script
	{
	public:
		JrBalrogScript();
		~JrBalrogScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;

		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;

		const Vector2& GetDirection() const { return mDirection; }
		void		   SetMinTimeToTrans(float time) { mMinTimeToTransition = time; }
		void		   SetDeathAnimDuration(float duration) { mDeathAnimDuration = duration; }
		void		   SetHp(UINT hp);

		void TakeDamage(UINT damage);

	private:
		void idle();
		void move();
		void chase();
		void attacked();
		void attack();
		void dead();

		void translateToIdle();
		void translateToMove();
		void translateToAttacked();
		void translateToAttack();
		void translateToDead();

		void resetDuration() { mDuration = 0.0f; }

		Monster* mMonster;
		Transform* mTransform;
		Rigidbody* mRigidbody;
		Animator* mAnimator;
		bool		 mbIsAttacked;
		Vector2		 mDirection;
		float		 mDuration;
		float		 mMinTimeToTransition;
		const float	 mChaseDuration;
		float		 mDeathAnimDuration;
		UINT		 mHp;
	};

} // namespace hs
