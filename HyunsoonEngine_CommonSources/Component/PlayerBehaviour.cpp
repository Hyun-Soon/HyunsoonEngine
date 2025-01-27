#include "PlayerBehaviour.h"
#include "GameObject/GameObject.h"
#include "Transform.h"

namespace hs
{
	PlayerBehaviour::PlayerBehaviour()
	{
	}

	PlayerBehaviour::~PlayerBehaviour()
	{
	}

	void PlayerBehaviour::Initialize()
	{
		mTransform = GetOwner()->GetComponent<Transform>();
	}

	void PlayerBehaviour::Update()
	{
		// if (mState == Player::ePlayerState::Idle
		//	&& Input::GetKeyDown(eKeyCode::A))
		//{
		//	mVel.x = -200.0f;
		//	mDirection = { -1.0f, 0.0f };
		// }
		// else if (mState == Player::ePlayerState::Idle
		//	&& Input::GetKeyUp(eKeyCode::A))
		//{
		//	mVel.x = 0.0f;
		// }

		// if (mState == Player::ePlayerState::Idle
		//	&& Input::GetKeyDown(eKeyCode::D))
		//{
		//	mVel.x = 200.0f;
		//	mDirection = { 1.0f, 0.0f };
		// }
		// else if (mState == Player::ePlayerState::Idle
		//	&& Input::GetKeyUp(eKeyCode::D))
		//{
		//	mVel.x = 0.0f;
		// }

		// if ((mState == Player::ePlayerState::Idle || mState == Player::ePlayerState::Move)
		//	&& Input::GetKeyDown(eKeyCode::Space))
		//{
		//	jump();
		// }
		// else if (mState == Player::ePlayerState::Jump
		//	&& Input::GetKeyDown(eKeyCode::Space))
		//{
		//	doubleJump();
		// }

		// if ((mState == Player::ePlayerState::Idle || mState == Player::ePlayerState::Jump || mState == Player::ePlayerState::DoubleJump)
		//	&& Input::GetKey(eKeyCode::Ctrl))
		//{
		//	// LuckySeven cast
		// }

		// updatePhysics();

		// if (mPos.y >= 600.0f)
		//{
		//	mState = Player::ePlayerState::Idle;
		//	mAcc.x = 0.0f;
		//	mAcc.y = 0.0f;
		//	color = RGB(0, 0, 255);
		// }
	}

	/*void PlayerBehaviour::LateUpdate()
	{
	}

	void PlayerBehaviour::Render(HDC& hdc)
	{
	}*/

} // namespace hs