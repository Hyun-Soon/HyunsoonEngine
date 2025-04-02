#pragma once

#include "Component/Animator.h"
#include "Component/Transform.h"
#include "Component/Rigidbody.h"
#include "Component/Script.h"

#include "../Object/Monster.h"

namespace hs
{
	class LandMonsterScript : public Script
	{
	public:
		LandMonsterScript();
		~LandMonsterScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;

		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;

		const Vector2& GetDirection() const { return mDirection; }

	private:
		void idle();
		void move();
		void chase();
		void attacked();

		Monster*	 mMonster;
		Transform*	 mTransform;
		Rigidbody*	 mRigidbody;
		Animator*	 mAnimator;
		bool		 mbIsAttacked;
		Vector2		 mDirection;
		std::wstring mDirString;
		float		 mDuration;
		const float	 mMinTimeToTransition;
		const float	 mChaseDuration;
	};

} // namespace hs
