#pragma once

#include <unordered_map>

#include "HuntingScene.h"
#include "VillageScene.h"

namespace hs
{
	class SceneManager
	{
	public:
		enum class eSceneType
		{
			Login, Village, Hunting,
		};

		static Scene* CreateScene(const std::wstring& name, const eSceneType type);
		static Scene* LoadScene(const std::wstring& name);

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

	private:
		static std::unordered_map<std::wstring, Scene*> mScenes;
		static Scene* mActiveScene;
	};
}
