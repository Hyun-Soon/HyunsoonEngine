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
		Vector2 curMapSize = CollisionManager::GetActiveCollisionMap()->GetResolution();
		Vector2 pos = mTransform->GetPosition();
		Vector2 adjustedPos = { std::clamp<float>(pos.x, 0, curMapSize.x - 1), std::clamp<float>(pos.y, 0, curMapSize.y - 1) };

		if (CollisionManager::CheckCollisionMap(adjustedPos) == true)
		{
			mTransform->SetPosition(CollisionManager::GetGroundPos(adjustedPos));
			if (mRigidbody->GetVelocity().y > 0.0f)
				mRigidbody->SetGrounded(true);
		}
		else
		{
			mTransform->SetPosition(adjustedPos);
			mRigidbody->SetGrounded(false);
		}
	}

	void LandMonsterScript::OnCollisionEnter(Collider* other)
	{
		if (other->GetLayerType() == enums::eLayerType::Projectile)
		{
			Player*	   player = Player::GetInstance();
			Transform* playerTr = player->GetComponent<Transform>();
			Vector2	   playerPos = playerTr->GetPosition();

			if (playerPos.x < mTransform->GetPosition().x)
			{
				mDirString = L"_L";
				mDirection = Vector2::Left;
			}
			else
			{
				mDirString = L"_R";
				mDirection = Vector2::Right;
			}

			mMonster->SetState(Monster::eMonsterState::Attacked);
			mAnimator->PlayAnimation(mMonster->GetName() + L"Attacked" + mDirString);
			mDuration = 0.0f;
			mbIsAttacked = true;
			mRigidbody->ResetVelocity();
			mTransform->SetPosition(mTransform->GetPosition() + mDirection * -3.0f);
			attacked(); // TODO :: change attakced() func to translateToAttacked(); attacked() func is just called when it's already attacked state.
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
		// //onCollisionEnter()
		// Idle -> Move
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
		mRigidbody->SetVelocity(mDirection * static_cast<Monster*>(GetOwner())->GetSpeed());
		mDuration = 0.0f;
	}

	void LandMonsterScript::move()
	{

		if (mDuration < mMinTimeToTransition)
			return;

		// move -> attacked
		// OnCollisionEnter()
		// Move -> Idle
		mRigidbody->SetVelocity(Vector2::Zero);
		mMonster->SetState(Monster::eMonsterState::Idle);
		mAnimator->PlayAnimation(mMonster->GetName() + L"Idle" + mDirString);
		mDuration = 0.0f;
	}

	void LandMonsterScript::chase()
	{
		Player*	   player = Player::GetInstance();
		Transform* playerTr = player->GetComponent<Transform>();
		Vector2	   playerPos = playerTr->GetPosition();

		if (playerPos.x < mTransform->GetPosition().x)
		{
			mDirString = L"_L";
			mDirection = Vector2::Left;
		}
		else
		{
			mDirString = L"_R";
			mDirection = Vector2::Right;
		}

		mRigidbody->SetVelocity(mDirection * static_cast<Monster*>(GetOwner())->GetSpeed());
		mMonster->SetState(Monster::eMonsterState::Move);
		mAnimator->PlayAnimation(mMonster->GetName() + L"Move" + mDirString);
		mDuration = 0.0f;
		mbIsAttacked = false;
	}

	void LandMonsterScript::attacked()
	{
		if (mDuration < 0.5f) // attacked animation duration
			return;

		mRigidbody->SetVelocity(Vector2::Zero);
		mMonster->SetState(Monster::eMonsterState::Chase);
		mAnimator->PlayAnimation(mMonster->GetName() + L"Move" + mDirString);
	}

} // namespace hs
