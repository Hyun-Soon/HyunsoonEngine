#include "Scene.h"

namespace hs
{
	Scene::Scene(eSceneType sceneType)
		: mSceneType(sceneType)
		, mGameObjects()
	{
	}

	Scene::~Scene()
	{
		for (GameObject* gameObj : mGameObjects)
			delete gameObj;
	}

	void Scene::Initialize()
	{
	}

	void Scene::Update()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->Update();
		}

		Player* player = Player::GetInstance();
		player->Update();
	}

	void Scene::LateUpdate()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->LateUpdate();
		}

		Player* player = Player::GetInstance();
		player->LateUpdate();
	}

	void Scene::Render(HDC& hdc)
	{
		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->Render(hdc);
		}

		Player* player = Player::GetInstance();
		player->Render(hdc);
	}

	void Scene::AddGameObject(GameObject* gameObject)
	{
		mGameObjects.push_back(gameObject);
	}

	const Scene::eSceneType Scene::GetType() const
	{
		return mSceneType;
	}
} // namespace hs