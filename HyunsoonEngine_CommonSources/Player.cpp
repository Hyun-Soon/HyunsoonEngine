#include "Player.h"

namespace hs
{
	Player::Player()
	{
	}

	Player::~Player()
	{
	}

	void Player::Update()
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

		GameObject::Update();
	}

	void Player::LateUpdate()
	{
	}

	void Player::Render(HDC& hdc)
	{
		int color = RGB(0, 0, 255);
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

	//void Player::UseSkill(size_t skillId)
	//{
	//	assert(skillId < mSkills.size());

	//	mSkills[skillId].Use();
	//}

	//void Player::UseItem(size_t slotId)
	//{
	//	assert(slotId < mInventory.size());

	//	mInventory[slotId].Use();
	//}

	/*void Player::PickUpItem()
	{

	}*/

}
