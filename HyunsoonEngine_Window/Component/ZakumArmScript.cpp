#include <cassert>

#include "TimeUtils.h"
#include "RandomUtils.h"

#include "../HyunsoonEngine_Window/Object/Zakum/ZakumArm.h"
#include "../HyunsoonEngine_Window/Object/Player.h"
#include "PlayerScript.h"
#include "ZakumArmScript.h"
#include "ProjectileScript.h"
#include "Application.h"

extern hs::Application app;

namespace hs
{
	ZakumArmScript::ZakumArmScript()
		: mState(ZakumArmState::Attack)
		, mHp(0)
		, mDuration(0.0f)
		, mDeathAnimDuration(0.0f)
		, mCooltime(0.0f)
		, mSkillRenderOffset(Vector2::Zero)
	{
	}

	ZakumArmScript::~ZakumArmScript()
	{
	}

	void ZakumArmScript::Initialize()
	{
		mHp = 1; //debug
		mCooltime = RandomUtils::GetRandomValueInt(10, 15);
		mDeathAnimDuration = 1.5f;

		uint8_t idx = static_cast<ZakumArm*>(GetOwner())->GetIndex();

		if (zakumArms::skillOrders[idx] == L"Attack")
		{
			mSkillFunc = std::bind(&ZakumArmScript::attackPlayer, this);
		}
		else if (zakumArms::skillOrders[idx] == L"AccuracyDrop")
		{
			mSkillFunc = std::bind(&ZakumArmScript::accuracyDrop, this);
		}
		else if (zakumArms::skillOrders[idx] == L"CannotJump")
		{
			mSkillFunc = std::bind(&ZakumArmScript::cannotJump, this);
		}
		else if (zakumArms::skillOrders[idx] == L"SkillLock")
		{
			mSkillFunc = std::bind(&ZakumArmScript::skillLock, this);
		}
	}

	void ZakumArmScript::Update()
	{
		mDuration += TimeUtils::GetDeltaTime();
		switch (mState)
		{
			case ZakumArmState::Attack:
				attack();
				break;
			case ZakumArmState::Dead:
				dead();
				break;
			default:
				assert(false);
				break;
		}
	}

	void ZakumArmScript::OnCollisionEnter(Collider* other)
	{
		if (other->GetLayerType() == enums::eLayerType::Projectile)
		{
			ProjectileScript* prjtScript = other->GetOwner()->GetComponent<ProjectileScript>();
			TakeDamage(prjtScript->GetRandomDamage());

			if (mHp == 0)
			{
				translateToDead();
			}
		}
	}

	void ZakumArmScript::OnCollisionStay(Collider* other)
	{
	}

	void ZakumArmScript::OnCollisionExit(Collider* other)
	{
	}

	void ZakumArmScript::TakeDamage(UINT damage)
	{
		if (mHp <= damage)
		{
			mHp = 0;
		}
		else
		{
			mHp -= damage;
		}
	}

	void ZakumArmScript::translateToDead()
	{
		resetDuration();
		mState = ZakumArmState::Dead;
		Animator* anim = GetOwner()->GetComponent<Animator>();
		anim->PlayAnimation(static_cast<Monster*>(GetOwner())->GetName() + L"Death");
	}

	void ZakumArmScript::attack()
	{
		if (mDuration < mCooltime)
			return;

		//assert(mSkillPtr);
		//mSkillPtr();
		mSkillFunc();
		resetDuration();
	}

	void ZakumArmScript::dead()
	{
		if (mDuration < mDeathAnimDuration)
			return;

		object::Destroy(GetOwner());
	}

	void ZakumArmScript::attackPlayer()
	{
		//PlayerScript->TakeDamage();
	}

	void ZakumArmScript::cannotJump()
	{
		Player::GetInstance()->GetComponent<PlayerScript>()->BuffOn(static_cast<unsigned short>(Player::ePlayerBuff::CannotJump));
	}

	void ZakumArmScript::skillLock()
	{
		Player::GetInstance()->GetComponent<PlayerScript>()->BuffOn(static_cast<unsigned short>(Player::ePlayerBuff::SkillLock));
	}

	void ZakumArmScript::accuracyDrop()
	{
		Player::GetInstance()->GetComponent<PlayerScript>()->BuffOn(static_cast<unsigned short>(Player::ePlayerBuff::AccuracyDrop));
	}

} // namespace hs
