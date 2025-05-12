#include <cassert>

#include "TimeUtils.h"
#include "RandomUtils.h"

#include "../Object/JrBalrog.h"
#include "../Object/Zakum/Zakum.h"
#include "../Resource/BuffInfo.h"
#include "PlayerScript.h"
#include "ZakumScript.h"
#include "ProjectileScript.h"
#include "Application.h"

extern hs::Application app;

namespace hs
{
	std::unordered_map<ZakumScript::eZakumPhase, std::wstring> ZakumScript::mPhaseToString = { 
		{ ZakumScript::eZakumPhase::Phase1, L"Phase1" },
		{ ZakumScript::eZakumPhase::Phase2, L"Phase2" },
		{ ZakumScript::eZakumPhase::Phase3, L"Phase3" } };

	ZakumScript::ZakumScript()
		: mState(ZakumScript::eZakumState::Attack)
		, mPhase(ZakumScript::eZakumPhase::Phase1)
		, mMaxHp(0)
		, mHp(0)
		, mDuration(0.0f)
		, mDeathAnimDuration(0.0f)
		, mCooltime(0.0f)
		, mSkillRenderOffset(Vector2::Zero)
		, mSkillList{}
	{
	}

	ZakumScript::~ZakumScript()
	{
	}

	void ZakumScript::Initialize()
	{
		mSkillList.resize(3);
		mSkillList[0] = std::bind(&ZakumScript::attackPlayer, this);
		mSkillList[1] = std::bind(&ZakumScript::castDebuff, this);
		mSkillList[2] = std::bind(&ZakumScript::genMonster, this);

		mDebuffList.resize(3);
		mDebuffList[0] = std::bind(&ZakumScript::cannotJump, this);
		mDebuffList[1] = std::bind(&ZakumScript::accuracyDrop, this);
		mDebuffList[2] = std::bind(&ZakumScript::skillLock, this);

		SetHp(15); // debug
		mCooltime = RandomUtils::GetRandomValueInt(10, 15);
		mDeathAnimDuration = 2.0f;

		
	}

	void ZakumScript::Update()
	{
		if (isArmAlive())
			return;

		mDuration += TimeUtils::GetDeltaTime();

		switch (mState)
		{
			case eZakumState::Attack:
				attack();
				break;
			case eZakumState::Dead:
				dead();
				break;
			default:
				assert(false);
				break;
		}
	}

	void ZakumScript::Render(HDC& hdc)
	{
		wchar_t str[50] = L"";

		std::wstring wstr;
		if (mPhase == eZakumPhase::Phase1)
			wstr = L"Phase1";
		else if (mPhase == eZakumPhase::Phase2)
			wstr = L"Phase2";
		else
			wstr = L"Phase3";

		wstr += L", Hp : " + std::to_wstring(mHp);
		swprintf_s(str, 50, L"state : %s", wstr.c_str());
		int len = wcsnlen_s(str, 50);

		TextOut(hdc, 0, 20, str, len);
	}

	// void ZakumScript::LateUpdate()
	//{
	//
	// }

	void ZakumScript::OnCollisionEnter(Collider* other)
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

	void ZakumScript::OnCollisionStay(Collider* other)
	{
	}

	void ZakumScript::OnCollisionExit(Collider* other)
	{
	}

	void ZakumScript::TakeDamage(UINT damage)
	{
		if (mHp <= damage)
		{
			mHp = 0;
		}
		else
		{
			mHp -= damage;
		}

		updatePhase();
	}

	void ZakumScript::SetHp(UINT hp)
	{
		mMaxHp = hp;
		mHp = hp;
	}

	void ZakumScript::updatePhase()
	{
		UINT hpRatio = mHp * 100 / mMaxHp;

		if ((mPhase == eZakumPhase::Phase1 && hpRatio < 66)
			|| (mPhase == eZakumPhase::Phase2 && hpRatio < 33)
			|| (mPhase == eZakumPhase::Phase3 && mHp == 0))
		{
			translateToDead();
		}
	}

	void ZakumScript::translateToDead()
	{
		mState = eZakumState::Dead;
		Animator* anim = GetOwner()->GetComponent<Animator>();
		anim->PlayAnimation(static_cast<Zakum*>(GetOwner())->GetName() + mPhaseToString[mPhase] + L"Death");

		resetDuration();
	}

	void ZakumScript::attack()
	{
		if (mDuration < mCooltime)
			return;

		int randIdx = RandomUtils::GetRandomValueInt(0, static_cast<int>(mPhase) - 1);

		mSkillList[randIdx]();
		resetDuration();
	}

	void ZakumScript::dead()
	{
		if (mDuration < mDeathAnimDuration)
			return;

		if (mPhase == ZakumScript::eZakumPhase::Phase3)
			object::Destroy(GetOwner());
		else
		{
			mPhase = static_cast<eZakumPhase>((static_cast<int>(mPhase) + 1));
			mState = eZakumState::Attack;
			Animator* anim = GetOwner()->GetComponent<Animator>();
			anim->PlayAnimation(static_cast<Zakum*>(GetOwner())->GetName() + mPhaseToString[mPhase] + L"Idle");
			resetDuration();
		}
	}

	void ZakumScript::attackPlayer()
	{
		//Player::GetInstance()->TakeDamage();
		//assert(1);
	}

	void ZakumScript::castDebuff()
	{
		int randIdx = RandomUtils::GetRandomValueInt(0, mDebuffList.size() - 1);

		mDebuffList[randIdx]();
	}

	void ZakumScript::genMonster()
	{
		//temp
		object::Instantiate<JrBalrog>(eLayerType::Monster, {400, 600});
	}

	void ZakumScript::cannotJump()
	{
		Player::GetInstance()->GetComponent<PlayerScript>()->BuffOn(static_cast<unsigned short>(buff::eBuff::CannotJump));
	}

	void ZakumScript::skillLock()
	{
		Player::GetInstance()->GetComponent<PlayerScript>()->BuffOn(static_cast<unsigned short>(buff::eBuff::SkillLock));
	}

	void ZakumScript::accuracyDrop()
	{
		Player::GetInstance()->GetComponent<PlayerScript>()->BuffOn(static_cast<unsigned short>(buff::eBuff::AccuracyDrop));
	}

	bool ZakumScript::isArmAlive()
	{
		return GetOwner()->HasChild();
	}

} // namespace hs
