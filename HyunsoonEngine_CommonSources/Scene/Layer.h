#pragma once

#include <vector>

#include "../Entity.h"
#include "../Enums/Enums.h"

namespace hs
{
	class GameObject;
	typedef std::vector<GameObject*>::iterator GameObjectIter;

	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC& hdc);
		virtual void Destroy();

		void						   AddGameObject(GameObject* gameObject);
		const std::vector<GameObject*> GetGameObjects() { return mGameObjects; }

	private:
		/*void findDeadGameObjects(OUT std::vector<GameObject*>& gameObjs);
		void deleteGameObjects(std::vector<GameObject*> gameObjs);
		void eraseGameObject();*/

		// eLayerType				 mType;
		std::vector<GameObject*> mGameObjects;
	};
} // namespace hs