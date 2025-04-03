#include <cassert>

#include "TimeUtils.h"
#include "RandomUtils.h"

#include "LandMonsterScript.h"
#include "Application.h"

extern hs::Application app;

namespace hs
{
	LandMonsterScript::LandMonsterScript()
		: mMonster(nullptr)
		, mTransform(nullptr)
		, mRigidbody(nullptr)
		, mAnimator(nullptr)
		, mbIsAttacked(false)
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

	void LandMonsterScript::LateUpdate()
	{
		Vector2 res = app.GetResolution();
		Vector2 pos = mTransform->GetPosition();

		pos.x = std::clamp<float>(pos.x, 0, res.x - 200);
		pos.y = std::clamp<float>(pos.y, 0, res.y - 200);

		mTransform->SetPosition(pos);
		if (pos.y >= res.y - 200)
			mRigidbody->SetGrounded(true);
	}

	void LandMonsterScript::OnCollisionEnter(Collider* other)
	{
		if (other->GetLayerType() == enums::eLayerType::Projectile)
		{
			attacked();
		}
	}

	void LandMonsterScript::OnCollisionStay(Collider* other)
	{
	}

	void LandMonsterScript::OnCollisionExit(Collider* other)
	{
	}

	void LandMonsterScript::idle()
	{
		// Idle -> Attacked
		if (mbIsAttacked)
		{
			mMonster->SetState(Monster::eMonsterState::Attacked);
			mAnimator->PlayAnimation(mMonster->GetName() + L"Attacked" + mDirString);
			mDuration = 0.0f;
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
			mDuration = 0.0f;
		}
	}

	void LandMonsterScript::move()
	{
		if (mbIsAttacked)
		{
			mMonster->SetState(Monster::eMonsterState::Attacked);
			mAnimator->PlayAnimation(mMonster->GetName() + L"Attacked" + mDirString);
			mDuration = 0.0f;
		}
		else
		{
			if (mDuration < mMinTimeToTransition)
				return;

			// Move -> Idle
			mMonster->SetState(Monster::eMonsterState::Idle);
			mAnimator->PlayAnimation(mMonster->GetName() + L"Idle" + mDirString);
			mDuration = 0.0f;
		}
	}

	void LandMonsterScript::chase()
	{
		mRigidbody->AddForce({ 0.0f, -300.0f }); // debug // need player logic
	}

	void LandMonsterScript::attacked()
	{
		mbIsAttacked = true;

		if (mDuration < 1.0f) // attacked animation duration
			return;

		mMonster->SetState(Monster::eMonsterState::Chase);
		mRigidbody->AddVelocity(mDirection * mMonster->GetSpeed());
		mAnimator->PlayAnimation(mMonster->GetName() + L"Move" + mDirString);
	}

} // namespace hs
