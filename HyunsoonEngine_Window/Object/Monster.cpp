#include "Monster.h"

namespace hs
{
	Monster::Monster()
		: GameObject()
		, bDirection(Vector2::Left)
		, mState(eMonsterState::Idle)
		, mSpeed(3.0f)
	{
	}

	Monster::~Monster()
	{
	}

	void Monster::SetState(eMonsterState state)
	{
		mState = state;
	}

	Monster::eMonsterState Monster::GetState() const
	{
		return mState;
	}

	float Monster::GetSpeed() const
	{
		return mSpeed;
	}

	// void Monster::Attack()
	//{
	//	if (isPlayerNearby() == false)
	//		return;
	//	// attack
	// }

	// void Monster::TakeDamage(uint32_t damage)
	//{
	//	if (damage > mHP)
	//	{
	//		mHP = 0;
	//		mState = DEAD;
	//	}
	//	else
	//	{
	//		mHP -= damage;
	//	}
	// }

	// bool Monster::isPlayerNearby()
	//{

	//	return false;
	//}
} // namespace hs