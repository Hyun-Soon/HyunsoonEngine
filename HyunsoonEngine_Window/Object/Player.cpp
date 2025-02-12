#include "Player.h"
#include "Component/Transform.h"
#include "Component/Animator.h"
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
		, mDirection(1.0f, 0.0f)
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
		/*SpriteRenderer* spr = AddComponent<SpriteRenderer>();

		graphics::Texture* texture = ResourceManager::Load<graphics::Texture>(L"player", L"../HyunsoonEngine_Window/MaplestoryResources/Common/CommonNotSprite/NPC/GM.png");
		spr->SetTexture(texture);*/

		Animator* animator = AddComponent<Animator>();
		graphics::Texture* playerIdle = ResourceManager::Find<graphics::Texture>(L"PlayerIdle_L");
		assert(playerIdle);
		animator->CreateAnimation(L"PlayerIdle_L", playerIdle, Vector2::Zero, { 64, 68 }, { 0, 0 }, 4, 0.3f);
		animator->PlayAnimation(L"PlayerIdle_L");

		GameObject::Initialize();
	}

	const Vector2& Player::GetDirection() const
	{
		return mDirection;
	}

	void Player::updatePhysics()
	{
	}

	void Player::jump()
	{
		// color = RGB(0, 0, 0);
		// mState = Player::ePlayerState::Jump;
		// mVel.y = -50.0f;
		// mAcc.y = -100.0f;
	}

	void Player::doubleJump()
	{
		/*color = RGB(100, 100, 100);
		mVel += mDirection * 100.0f;
		mAcc += -mDirection * 60.0f;*/
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
