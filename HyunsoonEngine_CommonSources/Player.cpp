#include "Player.h"

namespace hs
{
	Player::Player()
		: GameObject()
	{
	}

	Player::~Player()
	{
	}

	void Player::UseSkill(UINT skillId)
	{
		assert(skillId < mSkills.size());

		mSkills[skillId].Use();
	}

	void Player::UseItem(UINT slotId)
	{
		assert(slotId < mInventory.size());

		mInventory[slotId].Use();
	}

	/*void Player::PickUpItem()
	{

	}*/

}
