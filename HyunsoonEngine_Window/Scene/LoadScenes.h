#pragma once

#include "../../HyunsoonEngine_CommonSources/Scene/SceneManager.h"
#include "BeginnersTown/BeginnersTown1.h"
#include "BeginnersTown/BeginnersTown2.h"
#include "SouthFerry.h"

namespace hs
{
	void LoadScenes()
	{
		SceneManager::CreateScene<BeginnersTown1>(L"BeginnersTown1");
		SceneManager::CreateScene<BeginnersTown2>(L"BeginnersTown2");
		// SceneManager::CreateScene<SouthFerry>(L"SouthFerry");

		SceneManager::LoadScene(L"BeginnersTown2");
	}
} // namespace hs