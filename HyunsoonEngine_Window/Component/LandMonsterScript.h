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

	private:
		void idle();
		void move();
		void chase();
		void attacked();

		Monster*	 mMonster;
		Transform*	 mTransform;
		Rigidbody*	 mRigidbody;
		Animator*	 mAnimator;
		bool		 mbChasing;
		Vector2		 mDirection;
		std::wstring mDirString;
		float		 mDuration;
		const float	 mMinTimeToTransition;
		const float	 mChaseDuration;
	};

} // namespace hs
