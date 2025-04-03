#pragma once

#include "Layer.h"

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
		virtual void Destroy();

		void			 AddGameObject(GameObject* gameObject, enums::eLayerType layerLevel);
		void			 EraseGameObject(GameObject* gameObj);
		const eSceneType GetType() const;
		Layer*			 GetLayer(enums::eLayerType layerType) { return mLayers[(UINT)layerType]; }

	private:
		void createLayers();

		eSceneType			mSceneType;
		std::vector<Layer*> mLayers;
	};
} // namespace hs
