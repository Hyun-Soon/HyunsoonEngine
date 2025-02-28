#pragma once

#include "GameObject/GameObject.h"
#include "../Item/Inventory.h"

namespace hs
{
	static class Player : public GameObject
	{
	public:
		enum class ePlayerState
		{
			Idle = 0x1,
			Move = 0x2,
			Attack = 0x4,
			LyingDown = 0x8,
			Dead = 0x16,
			Jump = 0x32,
			DoubleJump = 0x64,
			Alert = 0x128,
			End,
		};

		static Player* GetInstance();

		virtual void Initialize() override;

		// const Vector2&	   GetDirection() const;
		// void			   SetDirection(Vector2 dir);
		const ePlayerState GetState() const;
		void			   SetState(ePlayerState state);

		// void UseSkill(size_t skillId);
		// void UseItem(size_t slotId);
		// void PickUpItem();

	private:
		Player();
		~Player();

		static Player* player;

		// Vector2		 mDirection;
		ePlayerState mState;
		uint16_t	 mHP;
		uint16_t	 mMP;

		// std::vector<Item> mInventory;
		// std::vector<Skill> mSkills;
	};

} // namespace hs