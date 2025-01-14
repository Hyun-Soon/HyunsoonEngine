#include "Player.h"

namespace hs
{
	Player Player::mPlayer;

	Player& Player::GetInstance()
	{
		return mPlayer;
	}

	Player::Player()
		: GameObject()
		, mVel(0.0f, 0.0f)
		, mAcc(0.0f, 0.0f)
		, mDirection(1)
		, mState(ePlayerState::Idle)
		, mHP(100)
		, mMP(100)
	{
	}

	Player::~Player()
	{
	}

	void Player::Update()
	{
		if (mState == Player::ePlayerState::Idle
			&& Input::GetKeyDown(eKeyCode::A))
		{
			mVel.x = -200.0f;
			mDirection = -1;
		}
		else if (mState == Player::ePlayerState::Idle
			&& Input::GetKeyUp(eKeyCode::A))
		{
			mVel.x = 0.0f;
		}

		if (mState == Player::ePlayerState::Idle
			&& Input::GetKeyDown(eKeyCode::D))
		{
			mVel.x = 200.0f;
			mDirection = 1;
		}
		else if (mState == Player::ePlayerState::Idle
			&& Input::GetKeyUp(eKeyCode::D))
		{
			mVel.x = 0.0f;
		}

		if ((mState == Player::ePlayerState::Idle || mState == Player::ePlayerState::Move)
			&& Input::GetKeyDown(eKeyCode::Space))
		{
			jump();
		}
		else if (mState == Player::ePlayerState::Jump
			&& Input::GetKeyDown(eKeyCode::Space))
		{
			doubleJump();
		}

		updatePhysics();

		GameObject::Update();

		if (mPos.y >= 600.0f)
		{
			mState = Player::ePlayerState::Idle;
			mAcc.x = 0.0f;
			mAcc.y = 0.0f;
			color = RGB(0, 0, 255);
		}
	}

	void Player::LateUpdate()
	{
	}

	void Player::Render(HDC& hdc)
	{

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

	void Player::updatePhysics()
	{
		float dt = Time::GetDeltaTime();
		float dt2 = dt * dt;

		mPos.x += mVel.x * dt + mAcc.x * dt2;
		mVel.x += mAcc.x * dt;

		mPos.y += mVel.y * dt + mAcc.y * dt2;
		mVel.y += mAcc.y * dt;
		mAcc.y += 0.5f;
	}

	void Player::jump()
	{
		color = RGB(0, 0, 0);
		mState = Player::ePlayerState::Jump;
		mVel.y = -50.0f;
		mAcc.y = -100.0f;
	}

	void Player::doubleJump()
	{
		color = RGB(100, 100, 100);
		mVel.x += mDirection * 100.0f;
		mAcc.x += -mDirection * 60.0f;
	}

	// void Player::UseSkill(size_t skillId)
	//{
	//	assert(skillId < mSkills.size());

	//	mSkills[skillId].Use();
	//}

	// void Player::UseItem(size_t slotId)
	//{
	//	assert(slotId < mInventory.size());

	//	mInventory[slotId].Use();
	//}

	/*void Player::PickUpItem()
	{

	}*/

} // namespace hs
