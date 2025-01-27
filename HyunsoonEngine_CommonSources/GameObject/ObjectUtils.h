#pragma once

#include "GameObject/GameObject.h"
#include "Scene/LayerTypes.h"
#include "MathTypes.h"

namespace hs
{
	namespace object
	{
		template <typename T>
		static T* Instantiate(hs::eLayerType type)
		{
			T*	   gameObject = new T();
			Scene* activeScene = SceneManager::GetActiveScene();
			Layer* layer = activeScene->GetLayer(type);
			layer->AddGameObject(gameObject);

			return gameObject;
		}

		template <typename T>
		static T* Instantiate(hs::eLayerType type, hs::Vector2 position)
		{
			T*	   gameObject = new T();
			Scene* activeScene = SceneManager::GetActiveScene();
			Layer* layer = activeScene->GetLayer(type);
			layer->AddGameObject(gameObject);

			Transform* tr = gameObject->GetComponent<Transform>();
			tr->SetPosition(position);

			return gameObject;
		}

	} // namespace object
} // namespace hs