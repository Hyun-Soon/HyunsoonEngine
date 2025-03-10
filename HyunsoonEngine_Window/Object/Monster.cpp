#include "Monster.h"

namespace hs
{
	Monster::Monster()
		: GameObject()
		, bDirection(Vector2::Left)
		, mState(eMonsterState::Idle)
	{
	}

	Monster::~Monster()
	{
	}

	void Monster::Update()
	{
		// random logic

		GameObject::Update();
	}

	void Monster::LateUpdate()
	{
	}

	void Monster::Render(HDC& hdc)
	{
		// int	   color = RGB(int(mPos.x * 3) % 256, int(mPos.x * 6) % 256, int(mPos.y * 9) % 256);
		// HBRUSH newBrush = CreateSolidBrush(color);
		// HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, newBrush);

		// HPEN newPen = CreatePen(PS_SOLID, 2, color);
		// HPEN oldPen = (HPEN)SelectObject(hdc, newPen);

		// Rectangle(hdc, 100.0f + mPos.x, 100.0f + mPos.y, 200.0f + mPos.x, 200.0f + mPos.y);

		// SelectObject(hdc, oldBrush);
		// SelectObject(hdc, oldPen);
		// DeleteObject(newBrush);
		// DeleteObject(newPen);
	}

	void Monster::SetState(eMonsterState state)
	{
		mState = state;
	}

	Monster::eMonsterState Monster::GetState() const
	{
		return mState;
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