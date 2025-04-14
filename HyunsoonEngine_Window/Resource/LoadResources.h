#pragma once

#include "../HyunsoonEngine_CommonSources/Resource/ResourceManager.h"
#include "../HyunsoonEngine_CommonSources/Resource/Texture.h"

namespace hs
{
	void LoadResources()
	{
		// Background
		{
			// ResourceManager::Load<graphics::Texture>(L"bg_Henesys", L"../HyunsoonEngine_Window/MaplestoryResources/Henesys_back.bmp");
			// ResourceManager::Load<graphics::Texture>(L"background1", L"../HyunsoonEngine_Window/MaplestoryResources/Common/CommonNotSprite/MapBackGround/MapBackGround5.png");
			// ResourceManager::Load<graphics::Texture>(L"background1", L"../HyunsoonEngine_Window/MaplestoryResource/Background_Henesys.bmp");
			ResourceManager::Load<graphics::Texture>(L"bg_BeginnersTown1", L"../HyunsoonEngine_Window/MaplestoryResources/BeginnersTown1/BeginnersTown1NotSprite/BeginnersTown1/BeginnersTown1Background.png");

			ResourceManager::Load<graphics::Texture>(L"bg_BeginnersTown2", L"../HyunsoonEngine_Window/MaplestoryResources/BeginnersTown2/BeginnersTown2NotSprite/BeginnersTown2/BeginnersTown2Background.png");

			ResourceManager::Load<graphics::Texture>(L"bg_CrossRoad", L"../HyunsoonEngine_Window/MaplestoryResources/CrossRoad/CrossRoadNotSprite/CrossRoad/CrossRoad.bmp");

			ResourceManager::Load<graphics::Texture>(L"bg_SouthFerry", L"../HyunsoonEngine_Window/MaplestoryResources/Southferry/SouthferryNotSprite/Map/SouthFerry.bmp");

			// ResourceManager::Load<graphics::Texture>(L"bg_KerningCityBack", L"../HyunsoonEngine_Window/MaplestoryResources/KerningCity/KerningCityNotSprite/Map/KerningCityBackGround.bmp");
			ResourceManager::Load<graphics::Texture>(L"bg_KerningCity", L"../HyunsoonEngine_Window/MaplestoryResources/KerningCity/KerningCityNotSprite/Map/KerningCity.bmp");

			ResourceManager::Load<graphics::Texture>(L"bg_ZakumRoad", L"../HyunsoonEngine_Window/MaplestoryResources/ZakumRoad1/ZakumRoad1NotSprite/Map/ZakumRoad.bmp");
			ResourceManager::Load<graphics::Texture>(L"bg_ZakumRoadBack", L"../HyunsoonEngine_Window/MaplestoryResources/ZakumRoad1/ZakumRoad1NotSprite/Map/ZakumRoadBackGround.bmp");

			ResourceManager::Load<graphics::Texture>(L"bg_AlterOfZakumEnt", L"../HyunsoonEngine_Window/MaplestoryResources/AlterOfZakumEnt/AlterOfZakumEntNotSprite/Map/AlterOfZakumEnt.bmp");
			ResourceManager::Load<graphics::Texture>(L"bg_AlterOfZakumEntLayer", L"../HyunsoonEngine_Window/MaplestoryResources/AlterOfZakumEnt/AlterOfZakumEntNotSprite/Map/AlterOfZakumEntLayer.bmp");

			ResourceManager::Load<graphics::Texture>(L"bg_ZakumLandScape1", L"../HyunsoonEngine_Window/MaplestoryResources/AlterOfZakumEnt/AlterOfZakumEntNotSprite/Map/ZakumLandScape1.bmp");
			ResourceManager::Load<graphics::Texture>(L"bg_ZakumLandScape2", L"../HyunsoonEngine_Window/MaplestoryResources/AlterOfZakumEnt/AlterOfZakumEntNotSprite/Map/ZakumLandScape2.bmp");
			ResourceManager::Load<graphics::Texture>(L"bg_ZakumLandScape3", L"../HyunsoonEngine_Window/MaplestoryResources/AlterOfZakumEnt/AlterOfZakumEntNotSprite/Map/ZakumLandScape3.bmp");
			ResourceManager::Load<graphics::Texture>(L"bg_ZakumLandScape4", L"../HyunsoonEngine_Window/MaplestoryResources/AlterOfZakumEnt/AlterOfZakumEntNotSprite/Map/ZakumLandScape4.bmp");

			ResourceManager::Load<graphics::Texture>(L"bg_AlterOfZakum", L"../HyunsoonEngine_Window/MaplestoryResources/AlterOfZakum/AlterOfZakumNotSprite/Map/AlterOfZakum/AlterOfZakum.bmp");
			ResourceManager::Load<graphics::Texture>(L"bg_AlterOfZakumLayer", L"../HyunsoonEngine_Window/MaplestoryResources/AlterOfZakum/AlterOfZakumNotSprite/Map/AlterOfZakum/AlterOfZakumLayer.bmp");
		}

		// Player
		{
			ResourceManager::Load<graphics::Texture>(L"PlayerIdle_L", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Idle_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"PlayerIdle_R", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Idle_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"PlayerAlert_L", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Alert_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"PlayerAlert_R", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Alert_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"PlayerWalk_L", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Walk_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"PlayerWalk_R", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Walk_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"PlayerJump_L", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Jump_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"PlayerJump_R", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Jump_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"PlayerLyingDown_L", L"../HyunsoonEngine_Window/MaplestoryResources/Character/LyingDown_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"PlayerLyingDown_R", L"../HyunsoonEngine_Window/MaplestoryResources/Character/LyingDown_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"PlayerSwing0_L", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Swing0_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"PlayerSwing0_R", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Swing0_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"PlayerSwing1_L", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Swing1_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"PlayerSwing1_R", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Swing1_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"PlayerSwing2_L", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Swing2_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"PlayerSwing2_R", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Swing2_R.bmp");
		}

		// Monster
		{
			ResourceManager::Load<graphics::Texture>(L"GreenSnailIdle_L", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/GreenSnail/GreenSnailIdle_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"GreenSnailIdle_R", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/GreenSnail/GreenSnailIdle_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"GreenSnailMove_L", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/GreenSnail/GreenSnailMove_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"GreenSnailMove_R", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/GreenSnail/GreenSnailMove_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"GreenSnailAttacked_L", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/GreenSnail/GreenSnailAttacked_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"GreenSnailAttacked_R", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/GreenSnail/GreenSnailAttacked_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"GreenSnailDeath_L", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/GreenSnail/GreenSnailDeath_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"GreenSnailDeath_R", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/GreenSnail/GreenSnailDeath_R.bmp");
		}

		// Item
		{
			ResourceManager::Load<graphics::Texture>(L"Shuriken_L", L"../HyunsoonEngine_Window/MaplestoryResources/Item/Shuriken_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"Shuriken_R", L"../HyunsoonEngine_Window/MaplestoryResources/Item/Shuriken_R.bmp");
		}

		// Portal
		{
			ResourceManager::Load<graphics::Texture>(L"Portal", L"../HyunsoonEngine_Window/MaplestoryResources/Common/CommonSprite/Portal/Portals.png");
		}

		// UI
		{
			ResourceManager::Load<graphics::Texture>(L"BottomBar", L"../HyunsoonEngine_Window/MaplestoryResources/UI/BottomBar.bmp");
		}
	}
} // namespace hs