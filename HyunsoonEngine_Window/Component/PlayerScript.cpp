#include <algorithm>

#include "RandomUtils.h"
#include "TimeUtils.h"
#include "PlayerScript.h"
#include "Application.h"

extern hs::Application app;

namespace hs
{
	PlayerScript::PlayerScript()
		: mPlayer(nullptr)
		, mTransform(nullptr)
		, mRigidbody(nullptr)
		, mAnimator(nullptr)
		, mDirection(-1.0f, 0.0f)
		, mDuration(0.0f)
		, mSpeed(0.0f)
		, mDirString(L"_L")
		, mJumpForce(0.0f, -1700.0f)
		, mDoubleJumpSpeed(500.0f, -10.0f)
	{
	}

	PlayerScript::~PlayerScript()
	{
	}

	void PlayerScript::Initialize()
	{
		mPlayer = static_cast<Player*>(GetOwner());
		mTransform = GetOwner()->GetComponent<Transform>();
		mRigidbody = GetOwner()->GetComponent<Rigidbody>();
		mAnimator = GetOwner()->GetComponent<Animator>();
		mSpeed = 100.0f;
	}

	void PlayerScript::Update()
	{
		// static Player*		 player = static_cast<Player*>(GetOwner());
		Player::ePlayerState state = mPlayer->GetState();

		switch (state)
		{
			case Player::ePlayerState::Idle:
				stand();
				break;
			case Player::ePlayerState::Move:
				walk();
				break;
				// case Player::ePlayerState::Alert:
				//	alert();
				//	break;
			case Player::ePlayerState::Jump:
				jump();
				break;
			case Player::ePlayerState::DoubleJump:
				doubleJump();
				break;
			case Player::ePlayerState::Attack:
				attack();
				break;
			case Player::ePlayerState::LyingDown:
				lieDown();
				break;
			//  case Player::ePlayerState::Dead:
			//	die();
			//	break;
			default:
				assert(false);
				break;
		}
	}

	void PlayerScript::LateUpdate()
	{
		Vector2 res = app.GetResolution();
		Vector2 pos = mTransform->GetPosition();

		pos.x = std::clamp<float>(pos.x, 0, 1400);
		pos.y = std::clamp<float>(pos.y, 0, 600);

		mTransform->SetPosition(pos);
		if (pos.y >= 599.9f)
			mRigidbody->SetGrounded(true);
	}

	// void PlayerScript::SetAnimator(Animator* animator)
	//{
	//	mAnimator = animator;
	// }

	void PlayerScript::stand()
	{
		// if (Input::GetKey(eKeyCode::Left))
		//{
		//	mTransform->SetPosition(mTransform->GetPosition() + Vector2(-1.0f, 0.0f));
		// }
		// else if (Input::GetKey(eKeyCode::Right))
		//{
		//	mTransform->SetPosition(mTransform->GetPosition() + Vector2(1.0f, 0.0f));
		// }
		//  Idle -> Walk
		if (Input::GetKeyDown(eKeyCode::Left))
		{
			mDirection = Vector2(-1, 0);
			mDirString = L"_L";
			mPlayer->SetState(Player::ePlayerState::Move);
			mAnimator->PlayAnimation(L"PlayerWalk_L");
			mRigidbody->AddVelocity(mDirection * mSpeed);
		}
		else if (Input::GetKeyDown(eKeyCode::Right))
		{
			mDirection = Vector2(1, 0);
			mDirString = L"_R";
			mPlayer->SetState(Player::ePlayerState::Move);
			mAnimator->PlayAnimation(L"PlayerWalk_R");
			mRigidbody->AddVelocity(mDirection * mSpeed);
		}
		//  Idle -> LyingDown
		else if (mRigidbody->IsGrounded() && Input::GetKeyDown(eKeyCode::Down))
		{
			mRigidbody->ResetVelocity();
			mPlayer->SetState(Player::ePlayerState::LyingDown);
			mAnimator->PlayAnimation(L"PlayerLyingDown" + mDirString);
		}
		// Idle -> Jump
		else if (Input::GetKeyDown(eKeyCode::V))
		{
			mPlayer->SetState(Player::ePlayerState::Jump);
			mAnimator->PlayAnimation(L"PlayerJump" + mDirString);
			mRigidbody->AddForce(mJumpForce);
			mRigidbody->SetGrounded(false);
		}
		//// Idle -> Attack
		else if (Input::GetKeyDown(eKeyCode::C))
		{
			mPlayer->SetState(Player::ePlayerState::Attack);
			std::wstring motion = RandomUtils::GetRandomValueWString(0, 2);
			mAnimator->PlayAnimation(L"PlayerSwing" + motion + mDirString);
		}
		//  Idle -> Alert
		//  After implementing monster
	}

	void PlayerScript::walk()
	{

		if (Input::GetKeyUp(eKeyCode::Left))
		{
			mRigidbody->ResetVelocity();
			if (Input::GetKey(eKeyCode::Right) || Input::GetKeyDown(eKeyCode::Right))
			{
				mDirection = Vector2(1.0f, 0.0f);
				mRigidbody->AddVelocity(mDirection * mSpeed);
				mDirString = L"_R";
				mAnimator->PlayAnimation(L"PlayerWalk" + mDirString);
			}
			else
			{
				mPlayer->SetState(Player::ePlayerState::Idle);
				mAnimator->PlayAnimation(L"PlayerIdle_L");
			}
		}
		else if (Input::GetKeyUp(eKeyCode::Right))
		{
			mRigidbody->AddVelocity(mDirection * -1 * mSpeed);
			if (Input::GetKey(eKeyCode::Left) || Input::GetKeyDown(eKeyCode::Left))
			{
				mDirection = Vector2(-1.0f, 0.0f);
				mRigidbody->AddVelocity(mDirection * mSpeed);
				mDirString = L"_L";
				mAnimator->PlayAnimation(L"PlayerWalk" + mDirString);
			}
			else
			{
				mPlayer->SetState(Player::ePlayerState::Idle);
				mAnimator->PlayAnimation(L"PlayerIdle_R");
			}
		}
		// Walk -> Attack
		if (Input::GetKeyDown(eKeyCode::C))
		{
			mRigidbody->ResetVelocity();
			mPlayer->SetState(Player::ePlayerState::Attack);
			std::wstring motion = RandomUtils::GetRandomValueWString(0, 2);
			mAnimator->PlayAnimation(L"PlayerSwing" + motion + mDirString);
		}
		//// Walk-> Jump
		else if (Input::GetKeyDown(eKeyCode::V))
		{
			mPlayer->SetState(Player::ePlayerState::Jump);
			mAnimator->PlayAnimation(L"PlayerJump" + mDirString);
			mRigidbody->AddForce(mJumpForce);
			mRigidbody->SetGrounded(false);
		}
		// Walk -> LyingDown
		else if (mRigidbody->IsGrounded() && Input::GetKeyDown(eKeyCode::Down))
		{
			mRigidbody->ResetVelocity();
			mPlayer->SetState(Player::ePlayerState::LyingDown);
			mAnimator->PlayAnimation(L"PlayerLyingDown" + mDirString);
		}
	}

	// void PlayerScript::alert()
	//{
	//	mDuration += TimeUtils::GetDeltaTime();

	//	// Alert -> Walk
	//	if (Input::GetKeyDown(eKeyCode::Left))
	//	{
	//		mDirection = Vector2(-1, 0);
	//		mDirString = L"_L";
	//		mPlayer->SetState(Player::ePlayerState::Move);
	//		mAnimator->PlayAnimation(L"PlayerWalk_L");
	//	}
	//	else if (Input::GetKeyDown(eKeyCode::Right))
	//	{
	//		mDirection = Vector2(1, 0);
	//		mDirString = L"_R";
	//		mPlayer->SetState(Player::ePlayerState::Move);
	//		mAnimator->PlayAnimation(L"PlayerWalk_R");
	//	}
	//	// Alert -> Attack
	//	else if (Input::GetKeyDown(eKeyCode::C))
	//	{
	//		mPlayer->SetState(Player::ePlayerState::Attack);
	//		std::wstring motion = RandomUtils::GetRandomValueWString(0, 2);
	//		mAnimator->PlayAnimation(L"PlayerSwing" + motion + mDirString);
	//	}
	//	// Alert -> Idle
	//	else if (mDuration >= 3.0f)
	//	{
	//		mPlayer->SetState(Player::ePlayerState::Idle);
	//		mAnimator->PlayAnimation(L"PlayerIdle" + mDirString);
	//	}
	//	// Alert -> Jump
	//	else if (Input::GetKeyDown(eKeyCode::V))
	//	{
	//		mPlayer->SetState(Player::ePlayerState::Jump);
	//		mAnimator->PlayAnimation(L"PlayerJump" + mDirString);
	//	}
	//	// Alert -> LyingDown
	//	else if (Input::GetKeyDown(eKeyCode::Down))
	//	{
	//		mPlayer->SetState(Player::ePlayerState::LyingDown);
	//		mAnimator->PlayAnimation(L"PlayerLyingDown" + mDirString);
	//	}
	//	else
	//		return;

	//	mDuration = 0.0f;
	//}

	void PlayerScript::jump()
	{
		// Jumping
		if (Input::GetKeyDown(eKeyCode::Left))
		{
			mDirection = Vector2(-1, 0);
			mDirString = L"_L";
			mAnimator->PlayAnimation(L"PlayerJump_L");
		}
		else if (Input::GetKeyDown(eKeyCode::Right))
		{
			mDirection = Vector2(1, 0);
			mDirString = L"_R";
			mAnimator->PlayAnimation(L"PlayerJump_R");
		}
		// Jump -> DoubleJump
		else if (Input::GetKeyDown(eKeyCode::V))
		{
			mPlayer->SetState(Player::ePlayerState::DoubleJump);
			Vector2 temp = mDoubleJumpSpeed;
			temp.x *= mDirection.x;
			mRigidbody->AddVelocity(temp);
			mAnimator->PlayAnimation(L"PlayerJump" + mDirString);
		}
		// Jump -> Attack
		else if (Input::GetKeyDown(eKeyCode::C))
		{
			mPlayer->SetState(Player::ePlayerState::Attack);
			std::wstring motion = RandomUtils::GetRandomValueWString(0, 2);
			mAnimator->PlayAnimation(L"PlayerSwing" + motion + mDirString);
		}
		// Jump -> Walk, Idle, LyingDown
		else if (mRigidbody->IsGrounded())
		{
			mRigidbody->ResetVelocity();
			if (Input::GetKey(eKeyCode::Left) || Input::GetKeyDown(eKeyCode::Left))
			{
				mDirection = Vector2(-1, 0);
				mPlayer->SetState(Player::ePlayerState::Move);
				mDirString = L"_L";
				mRigidbody->AddVelocity(mDirection * mSpeed);
				mAnimator->PlayAnimation(L"PlayerWalk" + mDirString);
			}
			else if (Input::GetKey(eKeyCode::Right) || Input::GetKeyDown(eKeyCode::Right))
			{
				mDirection = Vector2(1, 0);
				mPlayer->SetState(Player::ePlayerState::Move);
				mDirString = L"_R";
				mRigidbody->AddVelocity(mDirection * mSpeed);
				mAnimator->PlayAnimation(L"PlayerWalk" + mDirString);
			}
			else if (Input::GetKey(eKeyCode::Down) || Input::GetKeyDown(eKeyCode::Down))
			{
				mRigidbody->ResetVelocity();
				mPlayer->SetState(Player::ePlayerState::LyingDown);
				mAnimator->PlayAnimation(L"PlayerLyingDown" + mDirString);
			}
			else
			{
				mPlayer->SetState(Player::ePlayerState::Idle);
				mAnimator->PlayAnimation(L"PlayerIdle" + mDirString);
			}
		}
		// Jump -> Alert
	}

	void PlayerScript::doubleJump()
	{
		// Jumping
		if (Input::GetKeyDown(eKeyCode::Left))
		{
			mDirection = Vector2(-1, 0);
			mDirString = L"_L";
			mAnimator->PlayAnimation(L"PlayerJump_L");
		}
		else if (Input::GetKeyDown(eKeyCode::Right))
		{
			mDirection = Vector2(1, 0);
			mDirString = L"_R";
			mAnimator->PlayAnimation(L"PlayerJump_R");
		}
		// DoubleJump -> Attack
		else if (Input::GetKeyDown(eKeyCode::C))
		{
			mPlayer->SetState(Player::ePlayerState::Attack);
			std::wstring motion = RandomUtils::GetRandomValueWString(0, 2);
			mAnimator->PlayAnimation(L"PlayerSwing" + motion + mDirString);
		}
		// DoubleJump -> Walk, Idle, LyingDown
		else if (mRigidbody->IsGrounded())
		{
			mRigidbody->ResetVelocity();
			mRigidbody->ResetAcceleration();

			if (Input::GetKey(eKeyCode::Left) || Input::GetKeyDown(eKeyCode::Left))
			{
				mDirection = Vector2(-1, 0);
				mPlayer->SetState(Player::ePlayerState::Move);
				mDirString = L"_L";
				mRigidbody->AddVelocity(mDirection * mSpeed);
				mAnimator->PlayAnimation(L"PlayerWalk" + mDirString);
			}
			else if (Input::GetKey(eKeyCode::Right) || Input::GetKeyDown(eKeyCode::Right))
			{
				mDirection = Vector2(1, 0);
				mPlayer->SetState(Player::ePlayerState::Move);
				mDirString = L"_R";
				mRigidbody->AddVelocity(mDirection * mSpeed);
				mAnimator->PlayAnimation(L"PlayerWalk" + mDirString);
			}
			else if (Input::GetKey(eKeyCode::Down) || Input::GetKeyDown(eKeyCode::Down))
			{
				mRigidbody->ResetVelocity();
				mPlayer->SetState(Player::ePlayerState::LyingDown);
				mAnimator->PlayAnimation(L"PlayerLyingDown" + mDirString);
			}
			else
			{
				mPlayer->SetState(Player::ePlayerState::Idle);
				mAnimator->PlayAnimation(L"PlayerIdle" + mDirString);
			}
		}
		else
		{
			mRigidbody->AddAcceleration(mDirection * -10.0f);
		}
		// DoubleJump -> Alert
	}

	void PlayerScript::attack()
	{
		if (mRigidbody->IsGrounded())
		{
			mRigidbody->ResetVelocity();
			mRigidbody->ResetAcceleration();
		}

		mDuration += TimeUtils::GetDeltaTime();

		if (mDuration < 0.75f)
			return;

		mDuration = 0.0f;

		// Attack -> Attack
		if (Input::GetKey(eKeyCode::C))
		{
			std::wstring motion = RandomUtils::GetRandomValueWString(0, 2);
			mAnimator->PlayAnimation(L"PlayerSwing" + motion + mDirString);
		}
		else if (mRigidbody->IsGrounded())
		{
			mRigidbody->ResetVelocity();
			mRigidbody->ResetAcceleration();

			// Attack -> Walk
			if (Input::GetKey(eKeyCode::Left) || Input::GetKeyDown(eKeyCode::Left))
			{
				mPlayer->SetState(Player::ePlayerState::Move);
				mDirection = Vector2(-1, 0);
				mDirString = L"_L";
				mRigidbody->AddVelocity(mDirection * mSpeed);
				mAnimator->PlayAnimation(L"PlayerWalk_L");
			}
			else if (Input::GetKey(eKeyCode::Right) || Input::GetKeyDown(eKeyCode::Right))
			{
				mPlayer->SetState(Player::ePlayerState::Move);
				mDirection = Vector2(1, 0);
				mDirString = L"_R";
				mRigidbody->AddVelocity(mDirection * mSpeed);
				mAnimator->PlayAnimation(L"PlayerWalk_R");
			}
			// Attack -> Jump
			else if (Input::GetKeyDown(eKeyCode::V))
			{
				mPlayer->SetState(Player::ePlayerState::Jump);
				mAnimator->PlayAnimation(L"PlayerJump" + mDirString);
				mRigidbody->AddForce(mJumpForce);
				mRigidbody->SetGrounded(false);
			}
			else if (Input::GetKey(eKeyCode::Down) || Input::GetKeyDown(eKeyCode::Down))
			{
				mPlayer->SetState(Player::ePlayerState::LyingDown);
				mAnimator->PlayAnimation(L"PlayerLyingDown" + mDirString);
			}
			else
			{
				// temp //Alert check
				mPlayer->SetState(Player::ePlayerState::Idle);
				mAnimator->PlayAnimation(L"PlayerIdle" + mDirString);
			}
		}
	}

	void PlayerScript::lieDown()
	{
		if (Input::GetKey(eKeyCode::Down))
			return;

		if (Input::GetKeyUp(eKeyCode::Down))
		{
			// LyingDown -> Walk
			if (Input::GetKey(eKeyCode::Left) || Input::GetKeyDown(eKeyCode::Left))
			{
				mDirection = Vector2(-1, 0);
				mDirString = L"_L";
				mPlayer->SetState(Player::ePlayerState::Move);
				mAnimator->PlayAnimation(L"PlayerWalk_L");
				mRigidbody->AddVelocity(mDirection * mSpeed);
			}
			else if (Input::GetKey(eKeyCode::Right) || Input::GetKeyDown(eKeyCode::Right))
			{
				mDirection = Vector2(1, 0);
				mDirString = L"_R";
				mPlayer->SetState(Player::ePlayerState::Move);
				mAnimator->PlayAnimation(L"PlayerWalk_R");
				mRigidbody->AddVelocity(mDirection * mSpeed);
			}
			// LyingDown -> Jump
			else if (Input::GetKey(eKeyCode::V))
			{
				mPlayer->SetState(Player::ePlayerState::Jump);
				mAnimator->PlayAnimation(L"PlayerJump" + mDirString);
				mRigidbody->AddForce(mJumpForce);
				mRigidbody->SetGrounded(false);
			}
			// LyingDown -> Idle
			else
			{
				mPlayer->SetState(Player::ePlayerState::Idle);
				mAnimator->PlayAnimation(L"PlayerIdle" + mDirString);
			}
			// LyingDown -> Alert
		}
	}

} // namespace hs