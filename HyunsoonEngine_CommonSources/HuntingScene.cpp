#include "HuntingScene.h"

namespace hs
{
	HuntingScene::HuntingScene()
		: mMonsterGenPeriod(7) // temp
	{
	}

	HuntingScene::~HuntingScene()
	{
	}

	void HuntingScene::Initialize()
	{
		// test
		GameObject* pObj;

		pObj = new Monster(0, 0, 100);
		AddGameObject(pObj);

		pObj = new Monster(0, 0, 100);
		pObj->SetPosition(500, 500);
		AddGameObject(pObj);
	}

} // namespace hs
