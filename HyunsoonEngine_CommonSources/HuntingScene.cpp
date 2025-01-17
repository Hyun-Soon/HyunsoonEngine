#include "HuntingScene.h"

namespace hs
{
	HuntingScene::HuntingScene()
		: Scene(eSceneType::Hunting)
		, mMonsterGenPeriod(7) // temp
	{
	}

	HuntingScene::~HuntingScene()
	{
	}

	void HuntingScene::Initialize()
	{
		// test
		Monster* pMonster;

		pMonster = new Monster({ 0, 0 }, 0, 0, 100);
		AddGameObject(pMonster);
		mMonsters.push_back(pMonster);

		pMonster = new Monster({ 500, 500 }, 0, 0, 100);
		AddGameObject(pMonster);
		mMonsters.push_back(pMonster);
	}

	Monster* HuntingScene::FindNearestMonster(float range)
	{
		Player* pPlayer = Player::GetInstance();

		Vector2 playerPos = pPlayer->GetPosition();
		Vector2 playerDir = pPlayer->GetDirection();

		Monster* ret = nullptr;
		float	 minDist = FLT_MAX;

		for (Monster* pMon : mMonsters)
		{
			Vector2 monsterPos = pMon->GetPosition();

			if (playerDir.x < 0)
			{
				if (playerPos.x < monsterPos.x)
					continue;
			}
			else
			{
				if (playerPos.x > monsterPos.x)
					continue;
			}

			float dist = Vector2::Length(monsterPos, playerPos);
			if (abs(monsterPos.y - playerPos.y) < 100
				&& dist <= range
				&& dist < minDist)
			{
				ret = pMon;
				minDist = dist;
			}
		}

		return ret;
	}

} // namespace hs
