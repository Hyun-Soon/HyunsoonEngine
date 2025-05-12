#include <algorithm>
#include <cassert>

#include "RandomUtils.h"
#include "TimeUtils.h"
#include "PlayerScript.h"
#include "Application.h"
#include "Resource/ResourceManager.h"
#include "../Object/ObjectUtilsCustom.h"
#include "../Object/Projectile.h"
#include "../DirectionMap.h"
#include "../Object/Portal.h"
#include "../Object/Effect.h"
#include "../Resource/BuffInfo.h"

extern hs::Application app;

namespace hs
{
	namespace buff
	{
		static std::unordered_map<unsigned short, BuffInfo> buffInfoMap = {
			{ 1, { L"CannotJump", { 43, 41 }, 6, { 0, -60 } } },
			{ 2, { L"AccuracyDrop", { 48, 52 }, 7, { 10, -80 } } },
			{ 4, { L"SkillLock", { 73, 47 }, 10, { -20, -80 } } }
		};
	}

	PlayerScript::PlayerScript()
		: mPlayer(nullptr)
		, mTransform(nullptr)
		, mRigidbody(nullptr)
		, mAnimator(nullptr)
		, mDirection(-1.0f, 0.0f)
		, mDuration(0.0f)
		, mSpeed(0.0f)
		, mJumpVel(0.0f, -400.0f)
		, mDoubleJumpSpeed(500.0f, -30.0f)
		, mBuff(0)
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
		Player::ePlayerState state = mPlayer->GetState();

		assert(static_cast<unsigned short>(buff::eBuff::End) < USHRT_MAX);

		float dt = TimeUtils::GetDeltaTime();
		for (unsigned short buff = 1; buff < static_cast<unsigned short>(buff::eBuff::End); buff <<= 1)
		{
			if (IsBuffOn(buff))
			{
				mRemainingBuffTime[buff] -= dt;
				if (mRemainingBuffTime[buff] < 0.0f)
					BuffOff(buff);
			}
		}

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

		if (mPlayer->GetState() != Player::ePlayerState::Jump && CollisionManager::CheckCollisionMap(adjustedPos, animSize) == true)
		{
			Vector2 revDir = mRigidbody->GetVelocity().Normalize() * -1;
			adjustedPos = CollisionManager::GetPossiblePos(adjustedPos, revDir, animSize);
		}

		if (CollisionManager::CheckCollisionMap(adjustedPos + Vector2(0, 1), animSize))
		{
			mRigidbody->SetGrounded(true);
			mRigidbody->SetGravity(false);
		}
		else
		{
			mRigidbody->SetGrounded(false);
			mRigidbody->SetGravity(true);
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

		/*wchar_t				 str[50] = L"";
		bool		 result = IsBuffOn(static_cast<unsigned short>(buff::eBuff::SkillLock));
		bool		 result1 = IsBuffOn(static_cast<unsigned short>(buff::eBuff::CannotJump));
		bool				 result2 = IsBuffOn(static_cast<unsigned short>(buff::eBuff::AccuracyDrop));

		std::wstring		 wstr;
		if (result)
			wstr += L"SkillLock & ";
		if (result1)
			wstr += L"CannotJump & ";
		if (result2)
			wstr += L"AccuracyDrop";
		if (wstr.length() == 0)
			wstr = L"No Buff";
		swprintf_s(str, 50, L"state : %s", wstr.c_str());
		int len = wcsnlen_s(str, 50);

		TextOut(hdc, 0, 20, str, len);*/
	}

	void PlayerScript::OnCollisionEnter(Collider* other)
	{
		enums::eLayerType type = other->GetOwner()->GetLayerType();

		if (type == enums::eLayerType::Monster)
		{
			mRigidbody->AddVelocity(mDirection * Vector2(500.0f, 0.0f) * -1.0f + Vector2(0.0f, -600.0f));
			mRigidbody->SetGrounded(false);
		}
	}

	void PlayerScript::OnCollisionStay(Collider* other)
	{
		enums::eLayerType type = other->GetOwner()->GetLayerType();

		if (type == enums::eLayerType::Particle && Input::GetKeyDown(eKeyCode::Up))
		{
			Portal*		 portal = static_cast<Portal*>(other->GetOwner());
			std::wstring destination = portal->GetName();
			Scene*		 activeScene = SceneManager::LoadScene(destination);

			std::vector<GameObject*> objVec = activeScene->GetLayer(eLayerType::Particle)->GetGameObjects();
			mTransform->SetPosition(objVec[portal->GetDestPortalIdx()]->GetComponent<Transform>()->GetPosition() + Vector2(0, -30));
		}
	}

	void PlayerScript::OnCollisionExit(Collider* other)
	{
	}

	void PlayerScript::BuffOn(unsigned short buff)
	{
		mBuff |= buff;

		mRemainingBuffTime[buff] = 3.0f; // temp
		
		Effect* effect = new Effect();
		effect->SetLifetime(3.0f);
		effect->SetOffset(buff::buffInfoMap[buff].offset);
		effect->Initialize();
		Animator* anim = effect->GetComponent<Animator>();
		graphics::Texture* tex = ResourceManager::Find<graphics::Texture>(buff::buffInfoMap[buff].buffName);
		anim->CreateAnimation(buff::buffInfoMap[buff].buffName, tex, Vector2::Zero, buff::buffInfoMap[buff].imgSize, Vector2::Zero, buff::buffInfoMap[buff].spriteLength, 0.1f);
		anim->PlayAnimation(buff::buffInfoMap[buff].buffName);
	
		GetOwner()->AddChild(effect);
	}

	void PlayerScript::BuffOff(unsigned short buff)
	{
		mBuff &= ~buff;

		mRemainingBuffTime[buff] = 0.0f;
	}

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
		if (IsBuffOn(static_cast<unsigned short>(buff::eBuff::CannotJump)))
			return;

		resetDuration();
		mPlayer->SetState(Player::ePlayerState::Jump);
		mAnimator->PlayAnimation(L"PlayerJump" + dirStrMap[mDirection]);
		mRigidbody->AddVelocity(mJumpVel);
		mRigidbody->SetGrounded(false);
	}

	void PlayerScript::translateToDoubleJump()
	{
		if (IsBuffOn(static_cast<unsigned short>(buff::eBuff::CannotJump)))
			return;

		resetDuration();
		mPlayer->SetState(Player::ePlayerState::DoubleJump);
		mRigidbody->AddVelocity(mDoubleJumpSpeed * mDirection.x);
		mAnimator->PlayAnimation(L"PlayerJump" + dirStrMap[mDirection]);
	}

	void PlayerScript::translateToAttack()
	{
		if (IsBuffOn(static_cast<unsigned short>(buff::eBuff::SkillLock)))
			return;

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