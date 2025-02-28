#include "Player.h"
#include "Component/Transform.h"
#include "Component/Animator.h"
#include "Component/Rigidbody.h"
#include "../Component/PlayerScript.h"
#include "Resource/ResourceManager.h"
#include "Resource/Texture.h"

namespace hs
{
	Player* Player::player = nullptr;

	Player* Player::GetInstance()
	{
		if (player == nullptr)
		{
			player = new Player();
			player->Initialize();
		}
		return player;
	}

	Player::Player()
		: GameObject()
		, mState(ePlayerState::Idle)
		, mHP(100)
		, mMP(100)
	{
	}

	Player::~Player()
	{
	}

	void Player::Initialize()
	{
		Animator*		   animator = AddComponent<Animator>();
		graphics::Texture* playerIdle_L = ResourceManager::Find<graphics::Texture>(L"PlayerIdle_L");
		animator->CreateAnimation(L"PlayerIdle_L", playerIdle_L, Vector2::Zero, { 64, 69 }, { 0, 0 }, 4, 0.3f);
		animator->PlayAnimation(L"PlayerIdle_L");

		graphics::Texture* playerIdle_R = ResourceManager::Find<graphics::Texture>(L"PlayerIdle_R");
		animator->CreateAnimation(L"PlayerIdle_R", playerIdle_R, Vector2::Zero, { 64, 69 }, { 0, 0 }, 4, 0.3f);

		graphics::Texture* playerAlert_L = ResourceManager::Find<graphics::Texture>(L"PlayerAlert_L");
		animator->CreateAnimation(L"PlayerAlert_L", playerAlert_L, Vector2::Zero, { 64, 68 }, { 0, 0 }, 4, 0.4f);

		graphics::Texture* playerAlert_R = ResourceManager::Find<graphics::Texture>(L"PlayerAlert_R");
		animator->CreateAnimation(L"PlayerAlert_R", playerAlert_R, Vector2::Zero, { 64, 68 }, { 0, 0 }, 4, 0.4f);

		graphics::Texture* playerWalk_L = ResourceManager::Find<graphics::Texture>(L"PlayerWalk_L");
		animator->CreateAnimation(L"PlayerWalk_L", playerWalk_L, Vector2::Zero, { 64, 69 }, { 0, 0 }, 4, 0.3f);

		graphics::Texture* playerWalk_R = ResourceManager::Find<graphics::Texture>(L"PlayerWalk_R");
		animator->CreateAnimation(L"PlayerWalk_R", playerWalk_R, Vector2::Zero, { 64, 69 }, { 0, 0 }, 4, 0.3f);

		graphics::Texture* playerJump_L = ResourceManager::Find<graphics::Texture>(L"PlayerJump_L");
		animator->CreateAnimation(L"PlayerJump_L", playerJump_L, Vector2::Zero, { 64, 67 }, { 0, 0 }, 1, 0.3f);

		graphics::Texture* playerJump_R = ResourceManager::Find<graphics::Texture>(L"PlayerJump_R");
		animator->CreateAnimation(L"PlayerJump_R", playerJump_R, Vector2::Zero, { 64, 67 }, { 0, 0 }, 1, 0.3f);

		graphics::Texture* playerLyingDown_L = ResourceManager::Find<graphics::Texture>(L"PlayerLyingDown_L");
		animator->CreateAnimation(L"PlayerLyingDown_L", playerLyingDown_L, Vector2::Zero, { 72, 41 }, { 0, 0 }, 1, 0.3f);

		graphics::Texture* playerLyingDown_R = ResourceManager::Find<graphics::Texture>(L"PlayerLyingDown_R");
		animator->CreateAnimation(L"PlayerLyingDown_R", playerLyingDown_R, Vector2::Zero, { 72, 41 }, { 0, 0 }, 1, 0.3f);

		graphics::Texture* playerSwing0_L = ResourceManager::Find<graphics::Texture>(L"PlayerSwing0_L");
		animator->CreateAnimation(L"PlayerSwing0_L", playerSwing0_L, Vector2::Zero, { 69, 68 }, { 0, 0 }, 3, 0.25f);

		graphics::Texture* playerSwing0_R = ResourceManager::Find<graphics::Texture>(L"PlayerSwing0_R");
		animator->CreateAnimation(L"PlayerSwing0_R", playerSwing0_R, Vector2::Zero, { 69, 68 }, { 0, 0 }, 3, 0.25f);

		graphics::Texture* playerSwing1_L = ResourceManager::Find<graphics::Texture>(L"PlayerSwing1_L");
		animator->CreateAnimation(L"PlayerSwing1_L", playerSwing1_L, Vector2::Zero, { 70, 69 }, { 0, 0 }, 3, 0.25f);

		graphics::Texture* playerSwing1_R = ResourceManager::Find<graphics::Texture>(L"PlayerSwing1_R");
		animator->CreateAnimation(L"PlayerSwing1_R", playerSwing1_R, Vector2::Zero, { 70, 69 }, { 0, 0 }, 3, 0.25f);

		graphics::Texture* playerSwing2_L = ResourceManager::Find<graphics::Texture>(L"PlayerSwing2_L");
		animator->CreateAnimation(L"PlayerSwing2_L", playerSwing2_L, Vector2::Zero, { 69, 65 }, { 0, 0 }, 3, 0.25f);

		graphics::Texture* playerSwing2_R = ResourceManager::Find<graphics::Texture>(L"PlayerSwing2_R");
		animator->CreateAnimation(L"PlayerSwing2_R", playerSwing2_R, Vector2::Zero, { 69, 65 }, { 0, 0 }, 3, 0.25f);

		Rigidbody* rigidbody = AddComponent<Rigidbody>();
		rigidbody->SetGravity(true);
		// Vector2 temp = { 100.0f, -10.0f };
		// rigidbody->AddVelocity(temp);

		PlayerScript* ps = AddComponent<PlayerScript>();
		// GameObject::Initialize();
	}

	// const Vector2& Player::GetDirection() const
	//{
	//	return mDirection;
	// }

	// void Player::SetDirection(Vector2 dir)
	//{
	//	mDirection = dir;
	// }

	const Player::ePlayerState Player::GetState() const
	{
		return mState;
	}

	void Player::SetState(ePlayerState state)
	{
		mState = state;
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
