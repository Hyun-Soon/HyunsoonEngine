#include "VillageScene.h"

namespace hs
{
	VillageScene::VillageScene()
		: Scene(eSceneType::Village)
	{
	}

	VillageScene::~VillageScene()
	{
	}

	void VillageScene::Initialize()
	{
		// test
		GameObject* pObj;

		pObj = new Npc();
		AddGameObject(pObj);

		pObj = new Npc();
		pObj->SetPosition(500.0f, 0.0f);
		AddGameObject(pObj);
	}

} // namespace hs
