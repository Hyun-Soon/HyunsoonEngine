#pragma once

#include <unordered_map>

#include "Scene.h"

namespace hs
{
	class SceneManager
	{
	public:
		static Scene* CreateScene(const std::wstring& name)
		{
			Scene* scene = nullptr;

			if (mScenes.find(name) == mScenes.end())
			{
				scene = new Scene();

				scene->SetName(name);
				scene->Initialize();

				mScenes[name] = scene;
			}

			return scene;
		}

		static Scene* LoadScene(const std::wstring& name)
		{
			std::unordered_map<std::wstring, Scene*>::iterator iter = mScenes.find(name);

			if (iter == mScenes.end())
				return nullptr;

			mActiveScene = iter->second;

			return iter->second;
		}

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

	private:
		static std::unordered_map<std::wstring, Scene*> mScenes;
		static Scene* mActiveScene;
	};
}
