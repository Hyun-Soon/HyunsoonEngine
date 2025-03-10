#include "TimeUtils.h"
#include "RandomUtils.h"

#include "LandMonsterScript.h"

namespace hs
{
	LandMonsterScript::LandMonsterScript()
		: mMonster(nullptr)
		, mTransform(nullptr)
		, mRigidbody(nullptr)
		, mAnimator(nullptr)
		, mbChasing(false)
		, mDirection(Vector2::Left)
		, mDirString(L"_L")
		, mDuration(0.0f)
		, mMinTimeToTransition(3.0f)
		, mChaseDuration(5.0f)
	{
	}

	LandMonsterScript::~LandMonsterScript()
	{
	}

	void LandMonsterScript::Initialize()
	{
		mMonster = static_cast<Monster*>(GetOwner());
		mTransform = mMonster->GetComponent<Transform>();
		mRigidbody = mMonster->GetComponent<Rigidbody>();
		mAnimator = mMonster->GetComponent<Animator>();
	}

	void LandMonsterScript::Update()
	{
		// static Monster*		   monster = static_cast<Monster*>(GetOwner());
		Monster::eMonsterState state = mMonster->GetState();
		mDuration += TimeUtils::GetDeltaTime();

		switch (state)
		{
			case Monster::eMonsterState::Idle:
				idle();
				break;
			case Monster::eMonsterState::Move:
				move();
				break;
			case Monster::eMonsterState::Chase:
				chase();
				break;
			case Monster::eMonsterState::Attacked:
				attacked();
				break;
			default:
				assert(false);
				break;
		}
	}

	void LandMonsterScript::idle()
	{
		// Idle -> Attacked
		if (mbChasing)
		{
			mMonster->SetState(Monster::eMonsterState::Attacked);
			mAnimator->PlayAnimation(mMonster->GetName() + L"Attacked" + mDirString);
		}
		// Idle -> Move
		else
		{
			if (mDuration < mMinTimeToTransition)
				return;

			if (RandomUtils::GetRandomValueInt(0, 1))
			{
				mDirection = Vector2::Left;
				mDirString = L"_L";
			}
			else
			{
				mDirection = Vector2::Right;
				mDirString = L"_R";
			}
			mMonster->SetState(Monster::eMonsterState::Move);
			mAnimator->PlayAnimation(mMonster->GetName() + L"Move" + mDirString);
		}
	}

	void LandMonsterScript::move()
	{
	}

} // namespace hs
