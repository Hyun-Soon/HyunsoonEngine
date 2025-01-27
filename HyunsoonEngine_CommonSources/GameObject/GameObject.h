#pragma once

#include "Input/Input.h"
#include "MathTypes.h"
#include "Component/SpriteRenderer.h"
#include "Scene/LayerTypes.h"

namespace hs
{
	class GameObject
	{
	public:
		GameObject(eLayerType type);
		virtual ~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC& hdc);

		const enum class eLayerType GetLayerLevel() const;

		template <typename T>
		T* AddComponent()
		{
			T* component = new T();
			component->Initialize();
			component->SetOwner(this);
			mComponents.push_back(component);

			return component;
		}

		template <typename T>
		T* GetComponent()
		{
			T* component = nullptr;
			for (Component* comp : mComponents)
			{
				if (component = dynamic_cast<T*>(comp))
					return component;
			}
			return component;
		}

	private:
		// void repositionWithinBounds();
		void initializeTransform();

		const eLayerType		mLayerLevel;
		std::vector<Component*> mComponents;
	};
} // namespace hs