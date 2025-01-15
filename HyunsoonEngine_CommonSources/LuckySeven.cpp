#include "LuckySeven.h"
#include "Monster.h"
#include "Inventory.h"
#include "SceneManager.h"
#include "Shuriken.h"

namespace hs
{
	LuckySeven::LuckySeven()
		: mShurikenUsage(2)
	{
	}

	LuckySeven::~LuckySeven()
	{
	}

	void LuckySeven::Cast()
	{
		Inventory* pInventory = Inventory::GetInstance();

		Shuriken* pShuriken = pInventory->findShuriken();

		if (!pShuriken)
			return;

		if (pShuriken->Use(mShurikenUsage) == false)
			return;

		// 1. find Monster
		// 2. create shuriken object towards to monster
		/*Monster* pTarget = SceneManager::findNearestMonster();
		Position targetDir(0.0f, 0.0f);
		if (pTarget)
			targetDir = pTarget->GetPosition();
		else
			targetDir*/
		// target.TakeDamage(pShuriken->GetPower() * pAbility->GetMainStat() * randVal);
	}
} // namespace hs