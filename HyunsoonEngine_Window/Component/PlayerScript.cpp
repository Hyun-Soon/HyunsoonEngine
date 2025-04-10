#include <algorithm>
#include <cassert>

#include "RandomUtils.h"
#include "TimeUtils.h"
#include "PlayerScript.h"
#include "Application.h"
#include "../Object/ObjectUtilsCustom.h"
#include "../Object/Projectile.h"
#include "../DirectionMap.h"

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
		, mJumpVel(0.0f, -370.0f)
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
				idle();
				break;
			case Player::ePlayerState::Move:
				move();
				break;
			case Player::ePlayerState::Alert:
				alert();
				break;
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
		Vector2 curMapSize = CollisionManager::GetActiveCollisionMap()->GetResolution();
		Vector2 pos = mTransform->GetPosition();
		Vector2 adjustedPos = { std::clamp<float>(pos.x, 0, curMapSize.x - 1), std::clamp<float>(pos.y, 0, curMapSize.y - 1) };

		Vector2 animSize = mAnimator->GetAnimationSize();

		if (CollisionManager::CheckCollisionMap(adjustedPos, animSize) == true)
		{
			Vector2 revDir = mRigidbody->GetVelocity().Normalize() * -1;
			adjustedPos = CollisionManager::GetPossiblePos(adjustedPos, revDir, animSize);
		}

		if (CollisionManager::CheckCollisionMap(adjustedPos + Vector2(0, 1), animSize))
		{
			mRigidbody->SetGrounded(true);
		}
		else
		{
			mRigidbody->SetGrounded(false);
		}

		mTransform->SetPosition(adjustedPos);
	}

	void PlayerScript::Render(HDC& hdc)
	{
		// debug
		/*{
			wchar_t				 str[50] = L"";
			Player::ePlayerState state = static_cast<Player*>(GetOwner())->GetState();
			std::wstring		 wstr;
			if (state == Player::ePlayerState::Idle)
				wstr = L"Idle";
			else if (state == Player::ePlayerState::Move)
				wstr = L"Move";
			else if (state == Player::ePlayerState::Attack)
				wstr = L"Attack";
			else if (state == Player::ePlayerState::LyingDown)
				wstr = L"LyingDown";
			else if (state == Player::ePlayerState::Dead)
				wstr = L"Dead";
			else if (state == Player::ePlayerState::Jump)
				wstr = L"Jump";
			else if (state == Player::ePlayerState::DoubleJump)
				wstr = L"DoubleJump";
			else if (state == Player::ePlayerState::Alert)
				wstr = L"Alert";
			else
				wstr = L"None";
			swprintf_s(str, 50, L"state : %s", wstr.c_str());
			int len = wcsnlen_s(str, 50);

			TextOut(hdc, 0, 20, str, len);
		}*/
	}

	void PlayerScript::OnCollisionEnter(Collider* other)
	{
		enums::eLayerType type = other->GetOwner()->GetLayerType();

		if (type == enums::eLayerType::Monster)
		{
			mRigidbody->AddVelocity(mDirection * Vector2(500.0f, 0.0f) * -1.0f + Vector2(0.0f, -500.0f));
			mRigidbody->SetGrounded(false);
		}
	}

	void PlayerScript::OnCollisionStay(Collider* other)
	{
	}

	void PlayerScript::OnCollisionExit(Collider* other)
	{
	}

	// void PlayerScript::SetAnimator(Animator* animator)
	//{
	//	mAnimator = animator;
	// }

	void PlayerScript::translateToIdle()
	{
		resetDuration();
		mPlayer->SetState(Player::ePlayerState::Idle);
		mAnimator->PlayAnimation(L"PlayerIdle" + dirStrMap[mDirection]);
	}

	void PlayerScript::translateToMove(eKeyCode keyCode)
	{
		resetDuration();
		mDirection = keyDirMap[keyCode];
		mPlayer->SetState(Player::ePlayerState::Move);
		mAnimator->PlayAnimation(L"PlayerWalk" + dirStrMap[mDirection]);
		mRigidbody->AddVelocity(mDirection * mSpeed);
	}

	void PlayerScript::translateToAlert()
	{
		resetDuration();
		mPlayer->SetState(Player::ePlayerState::Alert);
		mAnimator->PlayAnimation(L"PlayerAlert" + dirStrMap[mDirection]);
		mDuration = 0.0f;
	}

	void PlayerScript::translateToJump()
	{
		resetDuration();
		mPlayer->SetState(Player::ePlayerState::Jump);
		mAnimator->PlayAnimation(L"PlayerJump" + dirStrMap[mDirection]);
		mRigidbody->AddVelocity(mJumpVel);
		mRigidbody->SetGrounded(false);
	}

	void PlayerScript::translateToDoubleJump()
	{
		resetDuration();
		mPlayer->SetState(Player::ePlayerState::DoubleJump);
		mRigidbody->AddVelocity(mDoubleJumpSpeed * mDirection.x);
		mAnimator->PlayAnimation(L"PlayerJump" + dirStrMap[mDirection]);
	}

	void PlayerScript::translateToAttack()
	{
		resetDuration();
		mPlayer->SetState(Player::ePlayerState::Attack);
		std::wstring motion = RandomUtils::GetRandomValueWString(0, 2);
		mAnimator->PlayAnimation(L"PlayerSwing" + motion + dirStrMap[mDirection]);

		Projectile* projectile = object::InstantiateProjectile(GetOwner());
	}

	void PlayerScript::translateToLyingDown()
	{
		resetDuration();
		mRigidbody->ResetVelocity();
		mPlayer->SetState(Player::ePlayerState::LyingDown);
		mAnimator->PlayAnimation(L"PlayerLyingDown" + dirStrMap[mDirection]);
	}

	void PlayerScript::idle()
	{
		//  Idle -> Move
		if (Input::GetKeyDown(eKeyCode::Left))
		{
			translateToMove(eKeyCode::Left);
		}
		else if (Input::GetKeyDown(eKeyCode::Right))
		{
			translateToMove(eKeyCode::Right);
		}
		//  Idle -> LyingDown
		else if (mRigidbody->IsGrounded() && Input::GetKeyDown(eKeyCode::Down))
		{
			translateToLyingDown();
		}
		// Idle -> Jump
		else if (Input::GetKeyDown(eKeyCode::V))
		{
			translateToJump();
		}
		// Idle -> Attack
		else if (Input::GetKeyDown(eKeyCode::C))
		{
			translateToAttack();
		}
		//  Idle -> Alert
		//  After implementing monster
	}

	void PlayerScript::move()
	{

		if (Input::GetKeyUp(eKeyCode::Left))
		{
			mRigidbody->ResetVelocity();
			if (Input::GetKey(eKeyCode::Right) || Input::GetKeyDown(eKeyCode::Right))
			{
				mDirection = Vector2(1.0f, 0.0f);
				mRigidbody->AddVelocity(mDirection * mSpeed);
				mAnimator->PlayAnimation(L"PlayerWalk" + dirStrMap[mDirection]);
			}
			else
			{
				translateToIdle();
			}
		}
		else if (Input::GetKeyUp(eKeyCode::Right))
		{
			mRigidbody->AddVelocity(mDirection * -1 * mSpeed);
			if (Input::GetKey(eKeyCode::Left) || Input::GetKeyDown(eKeyCode::Left))
			{
				mDirection = Vector2(-1.0f, 0.0f);
				mRigidbody->AddVelocity(mDirection * mSpeed);
				mAnimator->PlayAnimation(L"PlayerWalk" + dirStrMap[mDirection]);
			}
			else
			{
				translateToIdle();
			}
		}
		// Move -> Attack
		if (Input::GetKeyDown(eKeyCode::C))
		{
			translateToAttack();
		}
		// Move -> Jump
		else if (Input::GetKeyDown(eKeyCode::V))
		{
			translateToJump();
		}
		// Move -> LyingDown
		else if (mRigidbody->IsGrounded() && Input::GetKeyDown(eKeyCode::Down))
		{
			translateToLyingDown();
		}
	}

	void PlayerScript::alert()
	{
		mDuration += TimeUtils::GetDeltaTime();

		// Alert -> Move
		if (Input::GetKeyDown(eKeyCode::Left))
		{
			translateToMove(eKeyCode::Left);
		}
		else if (Input::GetKeyDown(eKeyCode::Right))
		{
			translateToMove(eKeyCode::Right);
		}
		// Alert -> Attack
		else if (Input::GetKeyDown(eKeyCode::C))
		{
			translateToAttack();
		}
		// Alert -> Jump
		else if (Input::GetKeyDown(eKeyCode::V))
		{
			translateToJump();
		}
		// Alert -> LyingDown
		else if (Input::GetKeyDown(eKeyCode::Down))
		{
			translateToLyingDown();
		}
		// Alert -> Idle
		else if (mDuration >= 3.0f)
		{
			translateToIdle();
		}
		else
			return;
	}

	void PlayerScript::jump()
	{
		// Jumping
		if (Input::GetKeyDown(eKeyCode::Left))
		{
			mDirection = Vector2(-1, 0);
			mAnimator->PlayAnimation(L"PlayerJump_L");
		}
		else if (Input::GetKeyDown(eKeyCode::Right))
		{
			mDirection = Vector2(1, 0);
			mAnimator->PlayAnimation(L"PlayerJump_R");
		}
		// Jump -> DoubleJump
		else if (Input::GetKeyDown(eKeyCode::V))
		{
			translateToDoubleJump();
		}
		// Jump -> Attack
		else if (Input::GetKeyDown(eKeyCode::C))
		{
			translateToAttack();
		}
		// Jump -> Move, Idle, LyingDown
		else if (mRigidbody->IsGrounded())
		{
			mRigidbody->ResetVelocity();
			if (Input::GetKey(eKeyCode::Left) || Input::GetKeyDown(eKeyCode::Left))
			{
				translateToMove(eKeyCode::Left);
			}
			else if (Input::GetKey(eKeyCode::Right) || Input::GetKeyDown(eKeyCode::Right))
			{
				translateToMove(eKeyCode::Right);
			}
			else if (Input::GetKey(eKeyCode::Down) || Input::GetKeyDown(eKeyCode::Down))
			{
				translateToLyingDown();
			}
			else
			{
				translateToIdle();
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
			mAnimator->PlayAnimation(L"PlayerJump_L");
		}
		else if (Input::GetKeyDown(eKeyCode::Right))
		{
			mDirection = Vector2(1, 0);
			mAnimator->PlayAnimation(L"PlayerJump_R");
		}
		// DoubleJump -> Attack
		else if (Input::GetKeyDown(eKeyCode::C))
		{
			translateToAttack();
		}
		// DoubleJump -> Move, Idle, LyingDown
		else if (mRigidbody->IsGrounded())
		{
			mRigidbody->ResetVelocity();
			mRigidbody->ResetAcceleration();

			if (Input::GetKey(eKeyCode::Left) || Input::GetKeyDown(eKeyCode::Left))
			{
				translateToMove(eKeyCode::Left);
			}
			else if (Input::GetKey(eKeyCode::Right) || Input::GetKeyDown(eKeyCode::Right))
			{
				translateToMove(eKeyCode::Right);
			}
			else if (Input::GetKey(eKeyCode::Down) || Input::GetKeyDown(eKeyCode::Down))
			{
				translateToLyingDown();
			}
			else
			{
				translateToIdle();
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
			translateToAttack();
		}
		else if (mRigidbody->IsGrounded())
		{
			mRigidbody->ResetVelocity();
			mRigidbody->ResetAcceleration();

			// Attack -> Walk
			if (Input::GetKey(eKeyCode::Left) || Input::GetKeyDown(eKeyCode::Left))
			{
				translateToMove(eKeyCode::Left);
			}
			else if (Input::GetKey(eKeyCode::Right) || Input::GetKeyDown(eKeyCode::Right))
			{
				translateToMove(eKeyCode::Right);
			}
			// Attack -> Jump
			else if (Input::GetKeyDown(eKeyCode::V))
			{
				translateToJump();
			}
			else if (Input::GetKey(eKeyCode::Down) || Input::GetKeyDown(eKeyCode::Down))
			{
				translateToLyingDown();
			}
			else
			{
				// temp //Alert check
				translateToAlert();
			}
		}
		else
		{
			// temp //Alert check
			translateToAlert();
		}
	}

	void PlayerScript::lieDown()
	{
		if (Input::GetKey(eKeyCode::Down))
			return;

		if (Input::GetKeyUp(eKeyCode::Down))
		{
			// LyingDown -> Move
			if (Input::GetKey(eKeyCode::Left) || Input::GetKeyDown(eKeyCode::Left))
			{
				translateToMove(eKeyCode::Left);
			}
			else if (Input::GetKey(eKeyCode::Right) || Input::GetKeyDown(eKeyCode::Right))
			{
				translateToMove(eKeyCode::Right);
			}
			// LyingDown -> Jump
			else if (Input::GetKey(eKeyCode::V))
			{
				translateToJump();
			}
			// LyingDown -> Idle
			else
			{
				translateToIdle();
			}
			// LyingDown -> Alert
		}
	}

} // namespace hs