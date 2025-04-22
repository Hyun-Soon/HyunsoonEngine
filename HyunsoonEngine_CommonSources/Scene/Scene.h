#pragma once

#include "Layer.h"
#include "../MathTypes.h"

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

		virtual void OnEnter();
		virtual void OnExit();

		void			 AddGameObject(GameObject* gameObject);
		void			 AddGameObject(GameObject* gameObject, enums::eLayerType layerLevel);
		void			 EraseGameObject(GameObject* gameObj);
		const eSceneType GetType() const;
		Layer*			 GetLayer(enums::eLayerType layerType) { return mLayers[(UINT)layerType]; }
		void			 SetCamLimit(Vector2 limit) { mCamLimit = limit; }
		Vector2			 GetCamLimit() { return mCamLimit; }

	private:
		void createLayers();

		eSceneType			mSceneType;
		std::vector<Layer*> mLayers;
		Vector2				mCamLimit;
	};
} // namespace hs
