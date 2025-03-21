#include "Layer.h"
#include "GameObject/GameObject.h"

namespace hs
{
	Layer::Layer()
	{
	}

	Layer::~Layer()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj)
				delete gameObj;
		}
	}

	void Layer::Initialize()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Initialize();
		}
	}

	void Layer::Update()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;
			GameObject::eGameObjectState state = gameObj->GetActive();
			if (state == GameObject::eGameObjectState::Paused
				|| state == GameObject::eGameObjectState::Dead)
				continue;

			gameObj->Update();
		}
	}

	void Layer::LateUpdate()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;
			GameObject::eGameObjectState state = gameObj->GetActive();
			if (state == GameObject::eGameObjectState::Paused
				|| state == GameObject::eGameObjectState::Dead)
				continue;

			gameObj->LateUpdate();
		}
	}

	void Layer::Render(HDC& hdc)
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;
			GameObject::eGameObjectState state = gameObj->GetActive();
			if (state == GameObject::eGameObjectState::Paused
				|| state == GameObject::eGameObjectState::Dead)
				continue;

			gameObj->Render(hdc);
		}
	}

	void Layer::Destroy()
	{
		for (GameObjectIter iter = mGameObjects.begin(); iter != mGameObjects.end();)
		{
			GameObject::eGameObjectState active = (*iter)->GetActive();
			if (active == GameObject::eGameObjectState::Dead)
			{
				GameObject* deathObj = (*iter);
				iter = mGameObjects.erase(iter);

				delete deathObj;
				deathObj = nullptr;

				continue;
			}

			iter++;
		}
	}

	void Layer::AddGameObject(GameObject* gameObject)
	{
		mGameObjects.push_back(gameObject);
	}
} // namespace hs
