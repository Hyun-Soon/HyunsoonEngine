//#include <cassert>
//
//#include "TimeUtils.h"
//#include "RandomUtils.h"
//
//#include "ZakumScript.h"
//#include "ProjectileScript.h"
//#include "Application.h"
//
//extern hs::Application app;
//
//namespace hs
//{
//	ZakumScript::ZakumScript()
//		: mState(ZakumArmState::Attack)
//		, mHp(0)
//		, mDuration(0.0f)
//		, mDeathAnimDuration(0.0f)
//		, mCooltime(0.0f)
//		, mSkillRenderOffset(Vector2::Zero)
//	//, mSkillPtr(nullptr)
//	{
//	}
//
//	ZakumScript::~ZakumScript()
//	{
//	}
//
//	void ZakumScript::Initialize()
//	{
//		mHp = 1; // debug
//		mCooltime = RandomUtils::GetRandomValueInt(10, 15);
//		mDeathAnimDuration = 1.5f;
//
//		// test
//		mSkillFunc = std::bind(&ZakumScript::attackPlayer, this);
//	}
//
//	void ZakumScript::Update()
//	{
//		mDuration += TimeUtils::GetDeltaTime();
//		switch (mState)
//		{
//			case ZakumArmState::Attack:
//				attack();
//				break;
//			case ZakumArmState::Dead:
//				dead();
//				break;
//			default:
//				assert(false);
//				break;
//		}
//	}
//
//	// void ZakumScript::LateUpdate()
//	//{
//	//
//	// }
//
//	void ZakumScript::OnCollisionEnter(Collider* other)
//	{
//		if (other->GetLayerType() == enums::eLayerType::Projectile)
//		{
//			ProjectileScript* prjtScript = other->GetOwner()->GetComponent<ProjectileScript>();
//			TakeDamage(prjtScript->GetRandomDamage());
//
//			if (mHp == 0)
//			{
//				translateToDead();
//			}
//		}
//	}
//
//	void ZakumScript::OnCollisionStay(Collider* other)
//	{
//	}
//
//	void ZakumScript::OnCollisionExit(Collider* other)
//	{
//	}
//
//	void ZakumScript::TakeDamage(UINT damage)
//	{
//		if (mHp <= damage)
//		{
//			mHp = 0;
//		}
//		else
//		{
//			mHp -= damage;
//		}
//	}
//
//	void ZakumScript::translateToDead()
//	{
//		resetDuration();
//		mState = ZakumArmState::Dead;
//		Animator* anim = GetOwner()->GetComponent<Animator>();
//		anim->PlayAnimation(static_cast<Monster*>(GetOwner())->GetName() + L"Death");
//	}
//
//	void ZakumScript::attack()
//	{
//		if (mDuration < mCooltime)
//			return;
//
//		// assert(mSkillPtr);
//		// mSkillPtr();
//		mSkillFunc();
//		resetDuration();
//	}
//
//	void ZakumScript::dead()
//	{
//		if (mDuration < mDeathAnimDuration)
//			return;
//
//		object::Destroy(GetOwner());
//	}
//
//	void ZakumScript::attackPlayer()
//	{
//		assert(1);
//	}
//
//	void ZakumScript::cannotJump()
//	{
//	}
//
//	void ZakumScript::skillLock()
//	{
//	}
//
//	void ZakumScript::accuracyDrop()
//	{
//	}
//
//} // namespace hs
