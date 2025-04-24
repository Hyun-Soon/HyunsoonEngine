#pragma once

#include "../../HyunsoonEngine_CommonSources/Scene/SceneManager.h"
#include "BeginnersTown/BeginnersTown1.h"
#include "BeginnersTown/BeginnersTown2.h"
#include "CrossRoad.h"
#include "SouthFerry.h"
#include "KerningCity.h"
#include "ZakumRoad.h"
#include "AlterOfZakumEnt.h"
#include "AlterOfZakum.h"

namespace hs
{
	void LoadScenes()
	{
		SceneManager::CreateScene<BeginnersTown1>(L"BeginnersTown1");
		SceneManager::CreateScene<BeginnersTown2>(L"BeginnersTown2");
		SceneManager::CreateScene<CrossRoad>(L"CrossRoad");
		SceneManager::CreateScene<SouthFerry>(L"SouthFerry");
		SceneManager::CreateScene<KerningCity>(L"KerningCity");
		SceneManager::CreateScene<ZakumRoad>(L"ZakumRoad");
		SceneManager::CreateScene<AlterOfZakumEnt>(L"AlterOfZakumEnt");
		SceneManager::CreateScene<AlterOfZakum>(L"AlterOfZakum");

		SceneManager::LoadScene(L"AlterOfZakum");
	}
} // namespace hs