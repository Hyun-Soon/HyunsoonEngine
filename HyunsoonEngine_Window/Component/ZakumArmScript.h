#pragma once

#include <functional>

#include "Component/Animator.h"
#include "Component/Transform.h"
#include "Component/Rigidbody.h"
#include "Component/Script.h"

#include "../Object/Monster.h"

namespace hs
{
	namespace zakumArms
	{
		static const std::vector<Vector2>				offsets = { { -220, -200 }, { -220, -150 }, { -220, -80 }, { -220, 0 }, { 80, -200 }, { 120, -150 }, { 125, -80 }, { 130, 0 } };
		static const std::vector<Vector2>				animSizes = { { 211, 229 }, { 238, 229 }, { 264, 206 }, { 267, 203 }, { 213, 226 }, { 248, 234 }, { 273, 214 }, { 267, 203 } };
		static const std::vector<Vector2>				deathAnimSizes = { { 285, 325 }, { 335, 308 }, { 350, 262 }, { 350, 260 }, { 305, 313 }, { 331, 305 }, { 334, 303 }, { 350, 260 } };
		static const std::vector<std::wstring>			skillOrders = { L"Attack", L"CannotJump", L"Attack", L"AccuracyDrop", L"Attack", L"Attack", L"SkillLock", L"Attack" };
	} // namespace zakumArms

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
