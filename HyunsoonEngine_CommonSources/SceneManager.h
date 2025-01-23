#pragma once

#include <unordered_map>

#include "HuntingScene.h"
#include "VillageScene.h"

namespace hs
{
	class Monster;
	class SceneManager
	{
	public:
		static Scene* CreateScene(const std::wstring& name, const Scene::eSceneType type);
		static Scene* LoadScene(const std::wstring& name);

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

		static Monster* FindNearestMonster(float range);
		static void		AddGameObject(GameObject* obj);

	private:
		SceneManager();
		~SceneManager();
		static std::unordered_map<std::wstring, Scene*> mScenes;
		static Scene*									mActiveScene;
	};
} // namespace hs
