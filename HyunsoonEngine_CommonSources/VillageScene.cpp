#include "VillageScene.h"

namespace hs
{
	VillageScene::VillageScene()
	{
	}

	VillageScene::~VillageScene()
	{
	}

	void VillageScene::Initialize()
	{
		//test
		GameObject* pObj;

		pObj = new Npc();
		AddGameObject(pObj);

		pObj = new Npc();
		pObj->SetPosition(500.0f, 0.0f);
		AddGameObject(pObj);

	}

	//void VillageScene::Update()
	//{
	//}

	//void VillageScene::LateUpdate()
	//{
	//}

	//void VillageScene::Render(HDC& hdc)
	//{
	//	for (Npc& npc : mNpcs)
	//	{
	//		npc.Render(hdc);
	//	}
	//}
}
