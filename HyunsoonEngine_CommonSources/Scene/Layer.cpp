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
		std::erase_if(mGameObjects,
			[](GameObject* gameObj) {
				return gameObj && gameObj->IsDead();
			});

		/*std::vector<GameObject*> deleteObjects = {};
		findDeadGameObjects(deleteObjects);
		eraseGameObject();
		deleteGameObjects(deleteObjects);*/

		/*for (GameObjectIter iter = mGameObjects.begin(); iter != mGameObjects.end();)
		{
			if ((*iter)->IsDead())
			{
				GameObject* deathObj = (*iter);
				iter = mGameObjects.erase(iter);

				delete deathObj;
				deathObj = nullptr;

				continue;
			}

			iter++;
		}*/
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

	// void Layer::findDeadGameObjects(OUT std::vector<GameObject*>& gameObjs)
	//{
	//	for (GameObject* gameObj : mGameObjects)
	//	{
	//		GameObject::eGameObjectState state = gameObj->GetState();
	//		if (state == GameObject::eState::Dead)
	//			gameObjs.push_back(gameObj);
	//	}
	// }

	// void Layer::deleteGameObjects(std::vector<GameObject*> deleteObjs)
	//{
	//	for (GameObject* obj : deleteObjs)
	//	{
	//		delete obj;
	//		obj = nullptr;
	//	}
	// }

	// void Layer::eraseDeadGameObject()
	//{
	//	std::erase_if(mGameObjects,
	//		[](GameObject* gameObj) {
	//			return (gameObj)->IsDead();
	//		});
	// }
} // namespace hs
