#include "Monster.h"

namespace hs
{
	Monster::Monster(bool dir, int state, uint16_t hp)
		: bDirection(dir)
		, mState(state)
		, mHP(hp)
	{
	}

	Monster::~Monster()
	{
	}

	void Monster::Update()
	{
		if (Input::GetKey(eKeyCode::A))
		{
			mPos.x -= mSpeed * Time::GetDeltaTime();
		}

		if (Input::GetKey(eKeyCode::D))
		{
			mPos.x += mSpeed * Time::GetDeltaTime();
		}

		if (Input::GetKey(eKeyCode::W))
		{
			mPos.y -= mSpeed * Time::GetDeltaTime();
		}

		if (Input::GetKey(eKeyCode::S))
		{
			mPos.y += mSpeed * Time::GetDeltaTime();
		}
	}

	void Monster::LateUpdate()
	{
	}

	void Monster::Render(HDC& hdc)
	{
		int color = RGB(int(mPos.x * 3) % 256, int(mPos.x * 6) % 256, int(mPos.y * 9) % 256);
		HBRUSH newBrush = CreateSolidBrush(color);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, newBrush);

		HPEN newPen = CreatePen(PS_SOLID, 2, color);
		HPEN oldPen = (HPEN)SelectObject(hdc, newPen);

		Rectangle(hdc, 100.0f + mPos.x, 100.0f + mPos.y, 200.0f + mPos.x, 200.0f + mPos.y);

		SelectObject(hdc, oldBrush);
		SelectObject(hdc, oldPen);
		DeleteObject(newBrush);
		DeleteObject(newPen);
	}

	void Monster::Attack()
	{
		if (isPlayerNearby() == false)
			return;
		//attack
	}



	bool Monster::isPlayerNearby()
	{

		return false;
	}
}