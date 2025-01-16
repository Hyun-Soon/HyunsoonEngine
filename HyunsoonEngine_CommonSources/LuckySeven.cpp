#include "LuckySeven.h"
#include "Monster.h"
#include "Inventory.h"
#include "SceneManager.h"
#include "Shuriken.h"

namespace hs
{
	LuckySeven::LuckySeven()
		: mShurikenUsage(2)
		, mRange(200)
	{
	}

	LuckySeven::~LuckySeven()
	{
	}

	void LuckySeven::Cast()
	{
		Player*	   pPlayer = Player::GetInstance();
		Inventory* pInventory = Inventory::GetInstance();

		Shuriken* pShuriken = pInventory->findShuriken();

		if (!pShuriken)
			return;

		if (!pShuriken->Use(mShurikenUsage))
			return;

		Monster* pTarget = SceneManager::FindNearestMonster(mRange);
		// SceneManager::AddGameObject(new Projectile());

		// take damage after collision
		// pTarget->TakeDamage(DamageUtils::CalculateDamage(pShuriken->GetPower()));
		// shuriken object create
		//
		// *pAbility->GetMainStat()
	}
} // namespace hs