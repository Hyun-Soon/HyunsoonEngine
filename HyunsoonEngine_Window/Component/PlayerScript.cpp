#include <algorithm>

#include "../Object/Player.h"

#include "TimeUtils.h"
#include "PlayerScript.h"
#include "Application.h"

extern hs::Application app;

namespace hs
{

	PlayerScript::PlayerScript()
		: Component(enums::eComponentType::Script)
		, mPlayer(nullptr)
		, mTransform(nullptr)
		, mRigidbody(nullptr)
		, mAnimator(nullptr)
		, mDirection(Vector2(-1, 0))
		, mDuration(0.0f)
		, mDirString(L"_L")
	{
	}

	PlayerScript::~PlayerScript()
	{
	}

	void PlayerScript::Initialize()
	{
		mPlayer = static_cast<Player*>(GetOwner());
		mTransform = mPlayer->GetComponent<Transform>();
		assert(mTransform);
		mRigidbody = mPlayer->GetComponent<Rigidbody>();
		assert(mRigidbody);
		mAnimator = mPlayer->GetComponent<Animator>();
		assert(mAnimator);
	}

	void PlayerScript::Update()
	{
		static Player*		 player = static_cast<Player*>(GetOwner());
		Player::ePlayerState state = player->GetState();
		/*mDirection = player->GetDirection();*/

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
			// case Player::ePlayerState::Jump:
			//	jump();
			//	break;
			// case Player::ePlayerState::DoubleJump:
			//	doubleJump();
			//	break;
			// case Player::ePlayerState::Attack:
			//	attack();
			//	break;
			// case Player::ePlayerState::LyingDown:
			//	lieDown();
			//	break;
			//  case Player::ePlayerState::Dead:
			//	die();
			//	break;
			default:
				break;
		}
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

	void PlayerScript::LateUpdate()
	{
		Vector2 res = app.GetResolution();
		Vector2 pos = mTransform->GetPosition();

		// pos.x = std::clamp<int>(pos.x, 0, res.x - 200);
		//  pos.y = std::clamp<int>(pos.y, 0, res.y - 200);
		// std::wstring before = L"before : " + std::to_wstring(pos.x) + L", " + std::to_wstring(pos.y) + L"\n";

		pos.x = std::clamp<float>(pos.x, 0, 1400);
		pos.y = std::clamp<float>(pos.y, 0, 600);

		// std::wstring after = L"after : " + std::to_wstring(pos.x) + L", " + std::to_wstring(pos.y) + L"\n";

		// OutputDebugString(before.c_str());
		// OutputDebugString(after.c_str());

		mTransform->SetPosition(pos);
		if (pos.y >= 599.9f)
			mRigidbody->SetGrounded(true);

		// float a = 0.9f;
		// float b = -0.9f;
		// float c = 0.9f;
		// float d = -0.9f;

		// a = std::clamp<float>(a, -10, 10); // 1.6
		// b = std::clamp<float>(b, -10, 10); // -1.6
		// c = std::clamp<int>(c, -10, 10);   // 1
		// d = std::clamp<int>(d, -10, 10);   // -1

		// std::wstring out = std::to_wstring(a) + L", " + std::to_wstring(b) + L", " + std::to_wstring(c) + L", " + std::to_wstring(d) + L"\n";
		// OutputDebugString(out.c_str());
	}

	// void PlayerScript::SetAnimator(Animator* animator)
	//{
	//	mAnimator = animator;
	// }

	std::wstring PlayerScript::getRandomValueString(int minVal, int maxVal)
	{
		static std::random_device				  rd;					// 하드웨어 난수 생성기
		static std::mt19937						  gen(rd());			// Mersenne Twister 엔진
		static std::uniform_int_distribution<int> dist(minVal, maxVal); // 0~2 균등 분포

		int ret = dist(gen);

		return std::to_wstring(ret);
	}

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
			// mPlayer->SetState(Player::ePlayerState::Move);
			mAnimator->PlayAnimation(L"PlayerWalk_L");
			mRigidbody->AddVelocity({ -100.0f, 0.0f });
		}
		else if (Input::GetKeyDown(eKeyCode::Right))
		{
			mDirection = Vector2(1, 0);
			mDirString = L"_R";
			// mPlayer->SetState(Player::ePlayerState::Move);
			mAnimator->PlayAnimation(L"PlayerWalk_R");
			mRigidbody->AddVelocity({ 100.0f, 0.0f });
		}
		//  Idle -> LyingDown
		//  else if (Input::GetKeyDown(eKeyCode::Down))
		//{
		//	mPlayer->SetState(Player::ePlayerState::LyingDown);
		//	mAnimator->PlayAnimation(L"PlayerLyingDown" + mDirString);
		// }
		//// Idle -> Jump
		// else if (Input::GetKeyDown(eKeyCode::V))
		//{
		//	mPlayer->SetState(Player::ePlayerState::Jump);
		//	mAnimator->PlayAnimation(L"PlayerJump" + mDirString);
		//	mRigidbody->AddForce({ 0.0f, -1500.0f });
		//	mRigidbody->SetGrounded(false);
		// }
		//// Idle -> Attack
		// else if (Input::GetKeyDown(eKeyCode::C))
		//{
		//	mPlayer->SetState(Player::ePlayerState::Attack);
		//	std::wstring motion = getRandomValueString(0, 2);
		//	mAnimator->PlayAnimation(L"PlayerSwing" + motion + mDirString);
		// }
		//  Idle -> Alert
		//  After implementing monster
	}

	void PlayerScript::walk()
	{
		if (Input::GetKeyUp(eKeyCode::Left))
		{
			mRigidbody->AddVelocity({ 100.0f, 0.0f });
			mPlayer->SetState(Player::ePlayerState::Idle);
			mAnimator->PlayAnimation(L"PlayerIdle_L");
		}
		else if (Input::GetKeyUp(eKeyCode::Right))
		{
			mRigidbody->AddVelocity({ -100.0f, 0.0f });
			mPlayer->SetState(Player::ePlayerState::Idle);
			mAnimator->PlayAnimation(L"PlayerIdle_R");
		}
		// Walk -> Attack
		// if (Input::GetKeyDown(eKeyCode::C))
		//{
		//	mPlayer->SetState(Player::ePlayerState::Attack);
		//	std::wstring motion = getRandomValueString(0, 2);
		//	mAnimator->PlayAnimation(L"PlayerSwing" + motion + mDirString);
		//}
		//// Walk-> Jump
		// else if (Input::GetKeyDown(eKeyCode::V))
		//{
		//	mPlayer->SetState(Player::ePlayerState::Jump);
		//	mAnimator->PlayAnimation(L"PlayerJump" + mDirString);
		// }
		//// Walk -> LyingDown
		// else if (Input::GetKeyDown(eKeyCode::Down))
		//{
		//	mPlayer->SetState(Player::ePlayerState::LyingDown);
		//	mAnimator->PlayAnimation(L"PlayerLyingDown" + mDirString);
		// }
		// if (Input::GetKeyUp(eKeyCode::Left))
		//{
		//	mRigidbody->AddVelocity(mDirection * -100.0f);
		//	// Walk -> Walk
		//	if (Input::GetKey(eKeyCode::Right)) // Releasing the left key while holding the right key
		//	{
		//		mDirection = Vector2(1, 0);
		//		mDirString = L"_R";
		//		mAnimator->PlayAnimation(L"PlayerWalk_R");
		//	}
		//	// Walk -> Idle
		//	else
		//	{
		//		mPlayer->SetState(Player::ePlayerState::Idle);
		//		mAnimator->PlayAnimation(L"PlayerIdle_L");
		//	}
		//}
		// else if (Input::GetKeyUp(eKeyCode::Right))
		//{
		//	mRigidbody->AddVelocity(mDirection * -100.0f);
		//	if (Input::GetKey(eKeyCode::Left))
		//	{
		//		mDirection = Vector2(-1, 0);
		//		mDirString = L"_L";
		//		mAnimator->PlayAnimation(L"PlayerWalk_L");
		//	}
		//	else
		//	{
		//		mPlayer->SetState(Player::ePlayerState::Idle);
		//		mAnimator->PlayAnimation(L"PlayerIdle_R");
		//	}
		//}
		// else
		//{
		//	Vector2 nowPos = mTransform->GetPosition() + mDirection;
		//	mTransform->SetPosition(nowPos);
		// }
		//  Walk -> Alert
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
	//		std::wstring motion = getRandomValueString(0, 2);
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

	// void PlayerScript::jump()
	//{
	//	// Jump -> Walk
	//	// check if landed
	//	if (Input::GetKeyDown(eKeyCode::Left))
	//	{
	//		mDirection = Vector2(-1, 0);
	//		mDirString = L"_L";
	//		mAnimator->PlayAnimation(L"PlayerJump_L");
	//	}
	//	else if (Input::GetKeyDown(eKeyCode::Right))
	//	{
	//		mDirection = Vector2(1, 0);
	//		mDirString = L"_R";
	//		mAnimator->PlayAnimation(L"PlayerJump_R");
	//	}
	//	// Jump -> DoubleJump
	//	else if (Input::GetKeyDown(eKeyCode::V))
	//	{
	//		mPlayer->SetState(Player::ePlayerState::Idle);
	//		mAnimator->PlayAnimation(L"PlayerIdle" + mDirString);
	//	}
	//	// Jump -> Attack
	//	else if (Input::GetKeyDown(eKeyCode::C))
	//	{
	//		mPlayer->SetState(Player::ePlayerState::Attack);
	//		std::wstring motion = getRandomValueString(0, 2);
	//		mAnimator->PlayAnimation(L"PlayerSwing" + motion + mDirString);
	//	}
	//	// Jump -> LyingDown
	//	else if (Input::GetKeyDown(eKeyCode::Down))
	//	{
	//		mPlayer->SetState(Player::ePlayerState::LyingDown);
	//		mAnimator->PlayAnimation(L"PlayerLyingDown" + mDirString);
	//	}
	//	// Jump -> Idle
	//	else
	//	{
	//		mPlayer->SetState(Player::ePlayerState::Idle);
	//		mAnimator->PlayAnimation(L"PlayerIdle" + mDirString);
	//	}
	//	// Jump -> Alert
	// }

	// void PlayerScript::doubleJump()
	//{
	//	// DoubleJump -> Attack
	//	if (Input::GetKeyDown(eKeyCode::C))
	//	{
	//		mPlayer->SetState(Player::ePlayerState::Attack);
	//		std::wstring motion = getRandomValueString(0, 2);
	//		mAnimator->PlayAnimation(L"PlayerSwing" + motion + mDirString);
	//	}
	//	// DoubleJump -> Idle
	//	else
	//	{
	//		mPlayer->SetState(Player::ePlayerState::Idle);
	//		mAnimator->PlayAnimation(L"PlayerIdle" + mDirString);
	//	}
	//	// DoubleJump -> Alert
	// }

	// void PlayerScript::attack()
	//{
	//	mDuration += TimeUtils::GetDeltaTime();

	//	if (mDuration < 0.9f)
	//		return;

	//	// Attack -> Attack
	//	if (Input::GetKey(eKeyCode::C))
	//	{
	//		std::wstring motion = getRandomValueString(0, 2);
	//		mAnimator->PlayAnimation(L"PlayerSwing" + motion + mDirString);
	//		mDuration = 0.0f;
	//	}
	//	// Attack -> Walk
	//	else if (Input::GetKeyDown(eKeyCode::Left))
	//	{
	//		mPlayer->SetState(Player::ePlayerState::Move);
	//		mDirection = Vector2(-1, 0);
	//		mDirString = L"_L";
	//		mAnimator->PlayAnimation(L"PlayerWalk_L");
	//		mDuration = 0.0f;
	//	}
	//	else if (Input::GetKeyDown(eKeyCode::Right))
	//	{
	//		mPlayer->SetState(Player::ePlayerState::Move);
	//		mDirection = Vector2(1, 0);
	//		mDirString = L"_R";
	//		mAnimator->PlayAnimation(L"PlayerWalk_R");
	//		mDuration = 0.0f;
	//	}
	//	// Attack -> Jump
	//	else if (Input::GetKeyDown(eKeyCode::V))
	//	{
	//		mPlayer->SetState(Player::ePlayerState::Jump);
	//		mDirection = Vector2(1, 0);
	//		mDirString = L"_R";
	//		mAnimator->PlayAnimation(L"PlayerWalk_R");
	//		mDuration = 0.0f;
	//	}
	//	// Attack -> LyingDown
	//	else if (Input::GetKeyDown(eKeyCode::Down))
	//	{
	//		mPlayer->SetState(Player::ePlayerState::LyingDown);
	//		mAnimator->PlayAnimation(L"LyingDown" + mDirString);
	//	}
	//	// Attack -> Alert
	//	else
	//	{
	//		mPlayer->SetState(Player::ePlayerState::Alert);
	//		mAnimator->PlayAnimation(L"PlayerAlert" + mDirString);
	//		mDuration = 0.0f;
	//	}
	//}

	// void PlayerScript::lieDown()
	//{
	//	if (Input::GetKey(eKeyCode::Down))
	//		return;

	//	if (Input::GetKeyUp(eKeyCode::Down))
	//	{
	//		// LyingDown -> Walk
	//		if (Input::GetKey(eKeyCode::Left) || Input::GetKeyDown(eKeyCode::Left))
	//		{
	//			mDirection = Vector2(-1, 0);
	//			mDirString = L"_L";
	//			mPlayer->SetState(Player::ePlayerState::Move);
	//			mAnimator->PlayAnimation(L"PlayerWalk_L");
	//		}
	//		else if (Input::GetKey(eKeyCode::Right) || Input::GetKeyDown(eKeyCode::Right))
	//		{
	//			mDirection = Vector2(1, 0);
	//			mDirString = L"_R";
	//			mPlayer->SetState(Player::ePlayerState::Move);
	//			mAnimator->PlayAnimation(L"PlayerWalk_R");
	//		}
	//		// LyingDown -> Jump
	//		else if (Input::GetKey(eKeyCode::V))
	//		{
	//			mPlayer->SetState(Player::ePlayerState::Jump);
	//			mAnimator->PlayAnimation(L"PlayerJump" + mDirString);
	//		}
	//		// LyingDown -> Idle
	//		else
	//		{
	//			mPlayer->SetState(Player::ePlayerState::Idle);
	//			mAnimator->PlayAnimation(L"PlayerIdle" + mDirString);
	//		}
	//		// LyingDown -> Alert
	//	}
	//}

} // namespace hs