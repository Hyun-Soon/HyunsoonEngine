#pragma once

#include "../../HyunsoonEngine_CommonSources/Scene/SceneManager.h"
#include "BeginnersTown/BeginnersTown1.h"
#include "VillageScene.h"

namespace hs
{
	void LoadScenes()
	{
		SceneManager::CreateScene<BeginnersTown1>(L"BeginnersTown1");

		SceneManager::LoadScene(L"BeginnersTown1");
	}
} // namespace hs