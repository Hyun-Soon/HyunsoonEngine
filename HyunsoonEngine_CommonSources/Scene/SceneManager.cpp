#include "Scene/SceneManager.h"
#include "GameObject/Monster.h"

namespace hs
{
	std::unordered_map<std::wstring, Scene*> SceneManager::mScenes = {};
	Scene*									 SceneManager::mActiveScene = nullptr;

	Scene* SceneManager::CreateScene(const std::wstring& name, const Scene::eSceneType type)
	{
		Scene* scene = nullptr;

		if (mScenes.find(name) == mScenes.end())
		{
			int sceneType = static_cast<int>(type);

			switch (sceneType)
			{
					// case 0:
					//	scene = new LoginScene();
					//	break;
				case 1:
					scene = new VillageScene();
					break;
				case 2:
					scene = new HuntingScene();
					break;
				default:
					break;
			}

			scene->SetName(name);
			scene->Initialize();

			mScenes[name] = scene;
		}

		return scene;
	}

	Scene* SceneManager::LoadScene(const std::wstring& name)
	{
		std::unordered_map<std::wstring, Scene*>::iterator iter = mScenes.find(name);

		if (iter == mScenes.end())
			return nullptr;

		mActiveScene = iter->second;

		return iter->second;
	}

	void SceneManager::Initialize()
	{
		// test
		// mActiveScene = new HuntingScene(1, 0, {});
		// mActiveScene = new VillageScene();
		CreateScene(L"Henesys", Scene::eSceneType::Village);
		// CreateScene(L"Mushrooms", Scene::eSceneType::Hunting);
		LoadScene(L"Henesys");
	}

	void SceneManager::Update()
	{
		if (Input::GetKeyDown(eKeyCode::Tab))
		{
			std::unordered_map<std::wstring, Scene*>::iterator it = mScenes.find(mActiveScene->GetName());
			if (it != mScenes.end())
			{
				++it;
				if (it == mScenes.end())
					mActiveScene = (mScenes.begin())->second;
				else
					mActiveScene = it->second;
			}
		}
		mActiveScene->Update();
	}

	void SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}

	void SceneManager::Render(HDC& hdc)
	{
		mActiveScene->Render(hdc);
	}

	Monster* SceneManager::FindNearestMonster(float range)
	{
		return mActiveScene->FindNearestMonster(range);
	}

	void SceneManager::AddGameObject(GameObject* obj, enums::eLayerType layerLevel)
	{
		mActiveScene->AddGameObject(obj, layerLevel);
	}
} // namespace hs