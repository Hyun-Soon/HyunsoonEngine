#include "Player.h"
#include "Component/Transform.h"

namespace hs
{
	Player Player::player;

	Player* Player::GetInstance()
	{
		return &player;
	}

	Player::Player()
		: GameObject(eLayerType::Player)
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
		Transform* transform = AddComponent<Transform>();

		GameObject::Initialize();
	}

	void Player::Update()
	{
		GameObject::Update();
	}

	void Player::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Player::Render(HDC& hdc)
	{
		GameObject::Render(hdc);

		// HBRUSH newBrush = CreateSolidBrush(color);
		// HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, newBrush);

		// HPEN newPen = CreatePen(PS_SOLID, 2, color);
		// HPEN oldPen = (HPEN)SelectObject(hdc, newPen);

		// Rectangle(hdc, 100.0f + mPos.x, 100.0f + mPos.y, 200.0f + mPos.x, 200.0f + mPos.y);

		// SelectObject(hdc, oldBrush);
		// SelectObject(hdc, oldPen);
		// DeleteObject(newBrush);
		// DeleteObject(newPen);
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
