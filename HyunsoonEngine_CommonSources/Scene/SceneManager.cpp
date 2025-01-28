#include "GameObject/Monster.h"
#include "Scene/SceneManager.h"
#include "Scene/BeginnersTown/BeginnersTown1.h"
#include "Scene/VillageScene.h"

namespace hs
{
	std::unordered_map<std::wstring, Scene*> SceneManager::mScenes;

	Scene* SceneManager::mActiveScene = nullptr;

	Scene* SceneManager::LoadScene(const std::wstring& name)
	{
		std::unordered_map<std::wstring, Scene*>::iterator iter = mScenes.find(name);

		if (iter == mScenes.end())
			return nullptr;

		mActiveScene = iter->second;
		// mActiveScene->OnEnter();

		return iter->second;
	}

	void SceneManager::Initialize()
	{
		// test
		const std::wstring mapName = L"Henesys";
		Scene*			   begginersTown1 = CreateScene<BeginnersTown1>(mapName);

		const std::wstring testMap = L"testScene";
		Scene*			   village = CreateScene<VillageScene>(testMap);
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