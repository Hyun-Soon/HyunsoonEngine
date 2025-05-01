#pragma once

#include <functional>

#include "Component/Animator.h"
#include "Component/Transform.h"
#include "Component/Rigidbody.h"
#include "Component/Script.h"

#include "../Object/Monster.h"

namespace hs
{
	class ZakumArmScript : public Script
	{
	public:
		enum class ZakumArmState
		{
			Attack,
			Dead,
		};

		ZakumArmScript();
		~ZakumArmScript();

		void Initialize() override;
		void Update() override;
		//void LateUpdate() override;
		
		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;

		void SetCooltime(float cooltime) { mCooltime = cooltime; }
		void SetSkillRenderOffset(Vector2 offset) { mSkillRenderOffset = offset; }
		//void SetSkill(void (*funcPtr)(void)) { mSkillPtr = funcPtr; }

		void TakeDamage(UINT damage);

	private:
		void resetDuration() { mDuration = 0.0f; }

		void translateToDead();

		void attack();
		void dead();

		void attackPlayer();
		void cannotJump();
		void skillLock();
		void accuracyDrop();

		ZakumArmState	mState;
		UINT			mHp;
		float			mDuration;
		float			mDeathAnimDuration;
		float			mCooltime;
		Vector2			mSkillRenderOffset;
		std::function<void()> mSkillFunc;
		//void			(*mSkillPtr)(void);
	};

} // namespace hs
