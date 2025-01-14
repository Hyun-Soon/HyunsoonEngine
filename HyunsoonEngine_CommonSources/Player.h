#pragma once

#include "GameObject.h"
#include "Inventory.h"

namespace hs
{
	static class Player : public GameObject
	{
	public:
		static Player& GetInstance();

		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC& hdc) override;

		// void UseSkill(size_t skillId);
		// void UseItem(size_t slotId);
		// void PickUpItem();

	private:
		enum class ePlayerState
		{
			Idle,
			Move,
			Jump,
			DoubleJump,
			UsingSkill,
			HangOn,
			Dead,
		};

		Player();
		~Player();

		void updatePhysics();
		void jump();
		void doubleJump();

		Velocity	 mVel;
		Acceleration mAcc;

		int			 mDirection;
		ePlayerState mState;
		uint16_t	 mHP;
		uint16_t	 mMP;
		Inventory	 mInventory;

		int color = RGB(0, 0, 255); // test

		static Player mPlayer;

		// std::vector<Item> mInventory;
		// std::vector<Skill> mSkills;
	};

} // namespace hs