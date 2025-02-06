#pragma once

#include "../HyunsoonEngine_CommonSources/Resource/ResourceManager.h"
#include "../HyunsoonEngine_CommonSources/Resource/Texture.h"

namespace hs
{
	void LoadResources()
	{

		//ResourceManager::Load<graphics::Texture>(L"PlayerIdle", L"C:/Users/Soon/Desktop/HyunsoonEngine/HyunsoonEngine_Window/MaplestoryResources/Character/Idle.png");
		ResourceManager::Load<graphics::Texture>(L"PlayerIdle", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Idle.png");
		ResourceManager::Load<graphics::Texture>(L"PlayerWalk", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Walk.png");
		ResourceManager::Load<graphics::Texture>(L"PlayerJump", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Jump.png");
	}
}