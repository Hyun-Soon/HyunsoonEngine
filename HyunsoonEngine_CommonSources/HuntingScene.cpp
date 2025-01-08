#include "HuntingScene.h"

namespace hs
{
	HuntingScene::HuntingScene(uint8_t monsterCnt, uint8_t monsterGenPeriod, std::vector<Monster> monsters)
		: mMonsterCount(monsterCnt)
		, mMonsterGenPeriod(monsterGenPeriod)
		, mMonsters(monsters)
	{
	}

	HuntingScene::~HuntingScene()
	{
	}

	void HuntingScene::Initialize()
	{
		//test
		mMonsters.emplace_back(0, 0, 100);
		mMonsters.emplace_back(0, 0, 100);
		mMonsters[1].SetPosition(500, 500);
	}

	void HuntingScene::Update()
	{
		for (Monster& monster : mMonsters)
			monster.Update();
	}

	void HuntingScene::LateUpdate()
	{
	}

	void HuntingScene::Render(HDC& hdc)
	{
		for (Monster& monster : mMonsters)
			monster.Render(hdc);
	}
}
