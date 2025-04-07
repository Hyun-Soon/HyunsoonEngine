#pragma once

#include <unordered_map>

#include "Scene.h"
#include "../CollisionManager.h"

namespace hs
{
	class SceneManager
	{
	public:
		template <typename T>
		static Scene* CreateScene(const std::wstring& name)
		{
			T* scene = new T();
			scene->SetName(name);
			mActiveScene = scene;
			CollisionManager::CreateCollisionMap(name);
			scene->Initialize();

			mScenes[name] = scene;

			return scene;
		}

		static Scene* LoadScene(const std::wstring& name);

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC& hdc);
		static void Destroy();
		static void Release();

		static void	  AddGameObject(GameObject* obj);
		static void	  AddGameObject(GameObject* obj, enums::eLayerType layerLevel);
		static Scene* GetActiveScene() { return mActiveScene; };

	private:
		static std::unordered_map<std::wstring, Scene*> mScenes;
		static Scene*									mActiveScene;
	};
} // namespace hs