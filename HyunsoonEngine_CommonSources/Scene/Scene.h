#pragma once

#include "Layer.h"

namespace hs
{
	class Monster;
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
		Monster*		 FindNearestMonster(float range);

	private:
		eSceneType			mSceneType;
		std::vector<Layer*> mLayers;
	};
} // namespace hs
