#pragma once

#include "../HyunsoonEngine_CommonSources/Resource/ResourceManager.h"
#include "../HyunsoonEngine_CommonSources/Resource/Texture.h"

namespace hs
{
	void LoadResources()
	{

		//ResourceManager::Load<graphics::Texture>(L"PlayerIdle", L"C:/Users/Soon/Desktop/HyunsoonEngine/HyunsoonEngine_Window/MaplestoryResources/Character/Idle.png");
		//ResourceManager::Load<graphics::Texture>(L"PlayerIdle", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Idle.png");
		ResourceManager::Load<graphics::Texture>(L"PlayerIdle_L", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Idle_L.bmp");
		ResourceManager::Load<graphics::Texture>(L"PlayerIdle_R", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Idle_R.bmp");
		ResourceManager::Load<graphics::Texture>(L"PlayerAlert_L", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Alert_L.bmp");
		ResourceManager::Load<graphics::Texture>(L"PlayerAlert_R", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Alert_R.bmp");
		//ResourceManager::Load<graphics::Texture>(L"PlayerIdle", L"C:/Users/Soon/Desktop/HyunsoonEngine/HyunsoonEngine_Window/MaplestoryResources/Character/Idle_bgrm.bmp");
		ResourceManager::Load<graphics::Texture>(L"PlayerWalk", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Walk.png");
		ResourceManager::Load<graphics::Texture>(L"PlayerJump", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Jump.png");
	}
}