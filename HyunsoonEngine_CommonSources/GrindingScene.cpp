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
	}

	void GrindingScene::Update()
	{
	}

	void GrindingScene::LateUpdate()
	{
	}

	void GrindingScene::Render(HDC& hdc)
	{
	}
}
