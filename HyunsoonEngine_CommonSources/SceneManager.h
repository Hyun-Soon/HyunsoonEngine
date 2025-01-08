#pragma once

#include <unordered_map>

#include "GrindingScene.h"

namespace hs
{
	class SceneManager
	{
	public:
		static Scene* CreateScene(const std::wstring& name);
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
