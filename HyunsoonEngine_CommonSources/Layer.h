#pragma once

#include <vector>

#include "Entity.h"

namespace hs
{
	class GameObject;
	class Layer : public Entity
	{
	public:
		enum class eLayerType
		{
			Background,
			Monster,
			Player,
			Item,
			Npc,
			End,
		};

		Layer();
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC& hdc);

		void AddGameObject(GameObject* gameObject);

	private:
		// eLayerType				 mType;
		std::vector<GameObject*> mGameObjects;
	};
} // namespace hs