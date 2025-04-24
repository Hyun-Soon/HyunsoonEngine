#include <cassert>

#include "TimeUtils.h"
#include "RandomUtils.h"

#include "JrBalrogScript.h"
#include "ProjectileScript.h"
#include "Application.h"
#include "../DirectionMap.h"

extern hs::Application app;

namespace hs
{
	JrBalrogScript::JrBalrogScript()
		: mMonster(nullptr)
		, mTransform(nullptr)
		, mRigidbody(nullptr)
		, mAnimator(nullptr)
		, mbIsAttacked(false)
		, mDirection(Vector2::Left)
		, mDuration(0.0f)
		, mMinTimeToTransition(3.0f)
		, mChaseDuration(5.0f)
		, mDeathAnimDuration(0.0f)
		, mHp(0)
	{
	}

	JrBalrogScript::~JrBalrogScript()
	{
	}

	void JrBalrogScript::Initialize()
	{
		mMonster = static_cast<Monster*>(GetOwner());
		mTransform = mMonster->GetComponent<Transform>();
		mRigidbody = mMonster->GetComponent<Rigidbody>();
		mAnimator = mMonster->GetComponent<Animator>();
	}

	void JrBalrogScript::Update()
	{
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
		case Monster::eMonsterState::Attack:
			attack();
			break;
		case Monster::eMonsterState::Dead:
			dead();
			break;
		default:
			assert(false);
			break;
		}
	}

	void JrBalrogScript::LateUpdate()
	{
		Vector2 curMapSize = CollisionManager::GetActiveCollisionMap()->GetResolution();
		Vector2 pos = mTransform->GetPosition();
		Vector2 adjustedPos = { std::clamp<float>(pos.x, 0, curMapSize.x - 1), std::clamp<float>(pos.y, 0, curMapSize.y - 1) };

		Vector2 animSize = mAnimator->GetAnimationSize();

		if (CollisionManager::CheckCollisionMap(adjustedPos + Vector2::Down, animSize) == true)
		{
			Vector2 revDir = mRigidbody->GetVelocity().Normalize() * -1;
			mTransform->SetPosition(CollisionManager::GetPossiblePos(adjustedPos, revDir, animSize));
			if (mRigidbody->GetVelocity().y > 0.0f)
			{
				mRigidbody->SetGrounded(true);
				mRigidbody->SetGravity(false);
			}
		}
		else
		{
			mTransform->SetPosition(adjustedPos);
			mRigidbody->SetGrounded(false);
			mRigidbody->SetGravity(true);
		}
	}

	void JrBalrogScript::OnCollisionEnter(Collider* other)
	{
		if (other->GetLayerType() == enums::eLayerType::Projectile)
		{
			ProjectileScript* prjtScript = other->GetOwner()->GetComponent<ProjectileScript>();
			TakeDamage(prjtScript->GetRandomDamage());

			Player* player = Player::GetInstance();
			Transform* playerTr = player->GetComponent<Transform>();
			Vector2	   playerPos = playerTr->GetPosition();

			if (playerPos.x < mTransform->GetPosition().x)
			{
				mDirection = Vector2::Left;
			}
			else
			{
				mDirection = Vector2::Right;
			}

			if (mHp == 0)
			{
				translateToDead();
			}
			else
			{
				translateToAttacked();
			}
		}
	}

	void JrBalrogScript::OnCollisionStay(Collider* other)
	{
	}

	void JrBalrogScript::OnCollisionExit(Collider* other)
	{
	}

	void JrBalrogScript::SetHp(UINT hp)
	{
		mHp = hp;
	}

	void JrBalrogScript::TakeDamage(UINT damage)
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

	void JrBalrogScript::idle()
	{
		// Idle -> Move
		if (mDuration < mMinTimeToTransition)
			return;


		translateToMove();
	}

	void JrBalrogScript::move()
	{
		if (mDuration < mMinTimeToTransition)
			return;

		// Move -> Idle
		translateToIdle();
	}

	void JrBalrogScript::chase()
	{
		Player* player = Player::GetInstance();
		Transform* playerTr = player->GetComponent<Transform>();
		Vector2	   playerPos = playerTr->GetPosition();

		if (playerPos.x < mTransform->GetPosition().x)
		{
			mDirection = Vector2::Left;
		}
		else
		{
			mDirection = Vector2::Right;
		}

		if (Vector2::Length(playerPos, mTransform->GetPosition()) < 300)
			translateToAttack();
		else
		{
			mRigidbody->SetVelocity(mDirection * static_cast<Monster*>(GetOwner())->GetSpeed());
			mMonster->SetState(Monster::eMonsterState::Move);
			mAnimator->PlayAnimation(mMonster->GetName() + L"Move" + dirStrMap[mDirection]);
			mDuration = 0.0f;
			mbIsAttacked = false;
		}
	}

	void JrBalrogScript::attacked()
	{
		if (mDuration < 0.5f) // attacked animation duration
			return;

		mMonster->SetState(Monster::eMonsterState::Chase);
	}

	void JrBalrogScript::attack()
	{
		if (mDuration < mMinTimeToTransition)
			return;

		mMonster->SetState(Monster::eMonsterState::Chase);
	}

	void JrBalrogScript::dead()
	{
		if (mDuration < mDeathAnimDuration)
			return;

		mMonster->SetActive(false);
	}

	void JrBalrogScript::translateToIdle()
	{
		resetDuration();
		mRigidbody->SetVelocity(Vector2::Zero);
		mMonster->SetState(Monster::eMonsterState::Idle);
		mAnimator->PlayAnimation(mMonster->GetName() + L"Idle" + dirStrMap[mDirection]);
	}

	void JrBalrogScript::translateToMove()
	{
		resetDuration();

		if (RandomUtils::GetRandomValueInt(0, 1))
		{
			mDirection = Vector2::Left;
		}
		else
		{
			mDirection = Vector2::Right;
		}

		mMonster->SetState(Monster::eMonsterState::Move);
		mAnimator->PlayAnimation(mMonster->GetName() + L"Move" + dirStrMap[mDirection]);
		mRigidbody->SetVelocity(mDirection * static_cast<Monster*>(GetOwner())->GetSpeed());
	}

	void JrBalrogScript::translateToAttacked()
	{
		resetDuration();
		mMonster->SetState(Monster::eMonsterState::Attacked);
		mAnimator->PlayAnimation(mMonster->GetName() + L"Attacked" + dirStrMap[mDirection]);
		mbIsAttacked = true;
		mRigidbody->ResetVelocity();
		mTransform->SetPosition(mTransform->GetPosition() + mDirection * -3.0f);
	}

	void JrBalrogScript::translateToAttack()
	{
		std::wstring num = std::to_wstring(RandomUtils::GetRandomValueInt(0, 1) + 1);

		resetDuration();
		mMonster->SetState(Monster::eMonsterState::Attack);
		mAnimator->PlayAnimation(mMonster->GetName() + L"Attack" + num + dirStrMap[mDirection]);
		mRigidbody->ResetVelocity();
	}

	void JrBalrogScript::translateToDead()
	{
		resetDuration();
		mMonster->SetState(Monster::eMonsterState::Dead);
		mAnimator->PlayAnimation(mMonster->GetName() + L"Death" + dirStrMap[mDirection]);
		mRigidbody->ResetVelocity();
	}

} // namespace hs
