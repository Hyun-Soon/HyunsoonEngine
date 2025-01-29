#pragma once

#include <vector>

#include "../Entity.h"
#include "../Enums/Enums.h"

namespace hs
{
	class GameObject;
	class Layer : public Entity
	{
	public:
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