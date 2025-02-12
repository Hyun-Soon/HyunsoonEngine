#pragma once

#include "../HyunsoonEngine_CommonSources/Resource/ResourceManager.h"
#include "../HyunsoonEngine_CommonSources/Resource/Texture.h"

namespace hs
{
	void LoadResources()
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
}