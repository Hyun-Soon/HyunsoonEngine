#pragma once

#include "Component/Transform.h"
#include "GameObject/GameObject.h"
#include "Enums/Enums.h"
#include "MathTypes.h"
#include "Scene/SceneManager.h"

namespace hs
{
	namespace object
	{
		template <typename T>
		static T* Instantiate() // must initialize layertype in constructor
		{
			T* gameObj = new T();
			gameObj->Initialize();
			SceneManager::AddGameObject(gameObj);

			return gameObj;
		}

		template <typename T>
		static T* Instantiate(hs::Vector2 position) // must initialize layertype in constructor
		{
			T* gameObj = new T();
			gameObj->Initialize();
			SceneManager::AddGameObject(gameObj);

			Transform* tr = gameObj->GetComponent<Transform>();
			tr->SetPosition(position);

			return gameObj;
		}

		template <typename T>
		static T* Instantiate(hs::enums::eLayerType layerLevel)
		{
			T* gameObj = new T();
			gameObj->SetLayerType(layerLevel);
			gameObj->Initialize();
			SceneManager::AddGameObject(gameObj, layerLevel);

			return gameObj;
		}

		template <typename T>
		static T* Instantiate(hs::enums::eLayerType layerLevel, hs::Vector2 position)
		{
			T* gameObj = new T();
			gameObj->SetLayerType(layerLevel);
			gameObj->Initialize();
			SceneManager::AddGameObject(gameObj, layerLevel);

			Transform* tr = gameObj->GetComponent<Transform>();
			tr->SetPosition(position);

			return gameObj;
		}

		// static void Destory(GameObject* obj)
		//{
		//	if (obj == nullptr)
		//		return;

		//	obj->Death();
		//}
	} // namespace object
} // namespace hs