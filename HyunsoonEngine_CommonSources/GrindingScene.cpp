#include "GrindingScene.h"

namespace hs
{
	GrindingScene::GrindingScene(uint8_t monsterCnt, uint8_t monsterGenPeriod, std::vector<Monster> monsters)
		: mMonsterCount(monsterCnt)
		, mMonsterGenPeriod(monsterGenPeriod)
		, mMonsters(monsters)
	{
	}

	GrindingScene::~GrindingScene()
	{
	}

	void GrindingScene::Initialize()
	{
		//test
		mMonsters.emplace_back(0, 0, 100);
		mMonsters.emplace_back(0, 0, 100);
		mMonsters[1].SetPosition(500, 500);
	}

	void GrindingScene::Update()
	{
		for (Monster& monster : mMonsters)
			monster.Update();
	}

	void GrindingScene::LateUpdate()
	{
	}

	void GrindingScene::Render(HDC& hdc)
	{
		for (Monster& monster : mMonsters)
			monster.Render(hdc);
	}
}
