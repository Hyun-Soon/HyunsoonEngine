#include "SceneManager.h"

namespace hs
{
	std::unordered_map<std::wstring, Scene*> SceneManager::mScenes = {};
	Scene* SceneManager::mActiveScene = nullptr;

	Scene* SceneManager::CreateScene(const std::wstring& name)
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
		//test
		mActiveScene = new GrindingScene(1, 0, {});
		mActiveScene->Initialize();
	}

	void SceneManager::Update()
	{
		mActiveScene->Update();
	}

	void SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}

	void SceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
	}
}