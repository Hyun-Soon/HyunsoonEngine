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
			if (gameObj->IsActive() == false)
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
			if (gameObj->IsActive() == false)
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
			if (gameObj->IsActive() == false)
				continue;

			gameObj->Render(hdc);
		}
	}

	void Layer::Destroy()
	{
		destroyObjects(mGameObjects);
	}

	void Layer::AddGameObject(GameObject* gameObject)
	{
		mGameObjects.push_back(gameObject);
	}

	void Layer::EraseGameObject(GameObject* eraseGameObj)
	{
		std::erase_if(mGameObjects,
			[=](GameObject* gameObj) {
				return gameObj == eraseGameObj;
			});
	}

	void Layer::destroyObjects(std::vector<GameObject*>& objs)
	{
		for (GameObject* obj : objs)
		{
			if (obj->HasChild())
				destroyObjects(obj->GetChilds());
		}

		std::erase_if(objs,
			[](GameObject* gameObj) {
				return gameObj && gameObj->IsDead();
			});
	}
} // namespace hs
