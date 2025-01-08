#include "VillageScene.h""

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
		mNpcs.emplace_back();
		mNpcs.emplace_back();
		mNpcs[1].SetPosition(500.0f, 0.0f);
	}

	void VillageScene::Update()
	{
	}

	void VillageScene::LateUpdate()
	{
	}

	void VillageScene::Render(HDC& hdc)
	{
		for (Npc& npc : mNpcs)
		{
			npc.Render(hdc);
		}
	}
}
