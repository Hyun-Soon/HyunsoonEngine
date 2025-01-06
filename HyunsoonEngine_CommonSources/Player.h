#pragma once

#include "GameObject.h"

namespace hs
{
	class Player : public GameObject
	{
	public:
		enum class ePlayerState
		{
			Idle, Move, Jump,
			DoubleJump, UsingSkill, HangOn,
		};

		Player();
		~Player();

		void UseSkill(UINT skillId);
		void UseItem(UINT slotId);
		//void PickUpItem();

	private:
		ePlayerState mState;
		uint16_t mHP;
		uint16_t mMP;

		std::vector<Item> mInventory;
		std::vector<Skill> mSkills;
	};

}