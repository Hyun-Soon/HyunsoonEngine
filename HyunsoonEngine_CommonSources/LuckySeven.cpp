#include "LuckySeven.h"
#include "Monster.h"
#include "Inventory.h"
#include "SceneManager.h"
#include "Shuriken.h"
#include "Projectile.h"

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

		Monster*	pTarget = SceneManager::FindNearestMonster(mRange);
		Projectile* projectile = new Projectile(pPlayer->GetPosition(), 100.0f, 10.0f, pTarget);
		SceneManager::AddGameObject(projectile);

		// *pAbility->GetMainStat()
	}
} // namespace hs