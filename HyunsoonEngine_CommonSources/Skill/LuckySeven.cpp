#include "LuckySeven.h"
#include "GameObject/Monster.h"
#include "Item/Inventory.h"
#include "Scene/SceneManager.h"
#include "Item/Shuriken.h"
#include "GameObject/Projectile.h"
#include "GameObject/Player.h"

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
		// Player*	   player = Player::GetInstance();
		// Inventory* inventory = Inventory::GetInstance();

		// Shuriken* shuriken = inventory->findShuriken();

		// if (!shuriken)
		//	return;

		// if (!shuriken->Use(mShurikenUsage))
		//	return;

		// Monster*	pTarget = SceneManager::FindNearestMonster(mRange);
		// Projectile* projectile = new Projectile(player->GetPosition(), 100.0f, 10.0f, pTarget);
		// SceneManager::AddGameObject(projectile);

		// *pAbility->GetMainStat()
	}
} // namespace hs