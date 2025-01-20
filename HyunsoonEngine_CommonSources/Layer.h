#pragma once

#include "Entity.h"
#include "GameObject.h"

namespace hs
{
	class Layer : public Entity
	{
	public:
		/*enum class eLayerType
		{
			Background,
			Player,
		};*/

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