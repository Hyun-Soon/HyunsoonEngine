#pragma once

#include "Layer.h"

namespace hs
{
	// class Monster;
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
		virtual void Destroy();

		void			 AddGameObject(GameObject* gameObject, enums::eLayerType layerLevel);
		const eSceneType GetType() const;
		// Monster*		 FindNearestMonster(float range);

	private:
		void createLayers();

		eSceneType			mSceneType;
		std::vector<Layer*> mLayers;
	};
} // namespace hs
