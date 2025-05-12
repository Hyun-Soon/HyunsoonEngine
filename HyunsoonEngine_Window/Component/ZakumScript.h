#pragma once

#include <functional>

#include "Component/Animator.h"
#include "Component/Transform.h"
#include "Component/Rigidbody.h"
#include "Component/Script.h"

#include "../Object/Monster.h"

namespace hs
{
	class ZakumScript : public Script
	{
	public:
		enum class eZakumState
		{
			Attack,
			Dead,
		};

		enum class eZakumPhase
		{
			Phase1 = 1,
			Phase2,
			Phase3,
		};

		ZakumScript();
		~ZakumScript();

		void Initialize() override;
		void Update() override;
		void Render(HDC& hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;

		void SetCooltime(float cooltime) { mCooltime = cooltime; }
		void SetSkillRenderOffset(Vector2 offset) { mSkillRenderOffset = offset; }
		// void SetSkill(void (*funcPtr)(void)) { mSkillPtr = funcPtr; }

		void TakeDamage(UINT damage);

		void SetHp(UINT hp);
		void SetDeathAnimDuration(float duration) { mDeathAnimDuration = duration; }


	private:
		void resetDuration() { mDuration = 0.0f; }

		void updatePhase();

		void translateToDead();

		void attack();
		void dead();

		void attackPlayer();
		void castDebuff();
		void genMonster();

		void cannotJump();
		void skillLock();
		void accuracyDrop();

		bool isArmAlive();

		eZakumState			   mState;
		eZakumPhase				mPhase;
		UINT					mMaxHp;
		UINT				  mHp;
		float				  mDuration;
		float				  mDeathAnimDuration;
		float				  mCooltime;
		Vector2				  mSkillRenderOffset;
		std::vector<std::function<void()>> mSkillList;
		std::vector<std::function<void()>> mDebuffList;

		static std::unordered_map<eZakumPhase, std::wstring> mPhaseToString;
	};

} // namespace hs
