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
		void						   EraseGameObject(GameObject* eraseGameObj);
		std::vector<GameObject*>& GetGameObjects() { return mGameObjects; }

	private:
		void destroyObjects(std::vector<GameObject*>& objs);
		// void findDeadGameObjects(OUT std::vector<GameObject*>& gameObjs);
		// void deleteGameObjects(std::vector<GameObject*> gameObjs);
		// void eraseDeadGameObject();

		// eLayerType				 mType;
		std::vector<GameObject*> mGameObjects;
	};
} // namespace hs