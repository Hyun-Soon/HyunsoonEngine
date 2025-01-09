#pragma once

#include "GameObject.h"

namespace hs
{
	class Player : public GameObject
	{
	public:

		Player();
		~Player();

		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC& hdc) override;

		//void UseSkill(size_t skillId);
		//void UseItem(size_t slotId);
		//void PickUpItem();

	private:
		enum class ePlayerState
		{
			Idle, Move, Jump, DoubleJump,
			UsingSkill, HangOn, Dead,
		};
		ePlayerState mState;
		uint16_t mHP;
		uint16_t mMP;

		//std::vector<Item> mInventory;
		//std::vector<Skill> mSkills;
	};

}