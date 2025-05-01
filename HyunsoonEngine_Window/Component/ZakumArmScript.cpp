#include <cassert>

#include "TimeUtils.h"
#include "RandomUtils.h"

#include "ZakumArmScript.h"
#include "ProjectileScript.h"
#include "Application.h"
#include "../DirectionMap.h"

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
		//, mSkillPtr(nullptr)
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

		//test
		mSkillFunc = std::bind(&ZakumArmScript::attackPlayer, this);
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

	//void ZakumArmScript::LateUpdate()
	//{
	//	
	//}

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
		assert(1);
	}

	void ZakumArmScript::cannotJump()
	{
	}

	void ZakumArmScript::skillLock()
	{
	}

	void ZakumArmScript::accuracyDrop()
	{
	}

} // namespace hs
