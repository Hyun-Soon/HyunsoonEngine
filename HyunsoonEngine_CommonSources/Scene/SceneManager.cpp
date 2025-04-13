#include "Scene/SceneManager.h"
#include "Input/Input.h"

namespace hs
{
	std::unordered_map<std::wstring, Scene*> SceneManager::mScenes;

	Scene* SceneManager::mActiveScene = nullptr;

	Scene* SceneManager::LoadScene(const std::wstring& name)
	{
		if (mActiveScene)
			mActiveScene->OnExit();

		std::unordered_map<std::wstring, Scene*>::iterator iter = mScenes.find(name);

		if (iter == mScenes.end())
			return nullptr;

		mActiveScene = iter->second;
		mActiveScene->OnEnter();

		return iter->second;
	}

	void SceneManager::Initialize()
	{
	}

	void SceneManager::Update()
	{
		if (Input::GetKeyDown(eKeyCode::Tab))
		{
			mActiveScene->OnExit();
			std::unordered_map<std::wstring, Scene*>::iterator it = mScenes.find(mActiveScene->GetName());
			if (it != mScenes.end())
			{
				++it;
				if (it == mScenes.end())
					mActiveScene = (mScenes.begin())->second;
				else
					mActiveScene = it->second;
			}
			mActiveScene->OnEnter();
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

	void SceneManager::Destroy()
	{
		mActiveScene->Destroy();
	}

	void SceneManager::Release()
	{
		for (std::unordered_map<std::wstring, Scene*>::iterator iter = mScenes.begin(); iter != mScenes.end(); iter++)
		{
			delete iter->second;
			iter->second = nullptr;
		}
	}

	void SceneManager::AddGameObject(GameObject* obj)
	{
		mActiveScene->AddGameObject(obj);
	}

	void SceneManager::AddGameObject(GameObject* obj, enums::eLayerType layerLevel)
	{
		mActiveScene->AddGameObject(obj, layerLevel);
	}
} // namespace hs