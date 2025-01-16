#pragma once

#include "Entity.h"
#include "Player.h"
#include "Monster.h"

namespace hs
{
	class Scene : public Entity
	{
	public:
		enum class eSceneType
		{
			Login,
			Village,
			Hunting,
		};

		Scene(eSceneType sceneType);
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC& hdc);

		void			 AddGameObject(GameObject* gameObject);
		const eSceneType GetType() const;

	private:
		eSceneType				 mSceneType;
		std::vector<GameObject*> mGameObjects;
		// Image backgroundImage;
	};
} // namespace hs
