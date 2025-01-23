#pragma once

#include "Input.h"
#include "MathTypes.h"
#include "Component/Component.h"
#include "Layer.h"

namespace hs
{
	class GameObject
	{
	public:
		GameObject(Layer::eLayerType type);
		virtual ~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC& hdc);

		const enum class Layer::eLayerType GetLayerLevel() const;

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
		T* GetComponent(std::wstring compName)
		{
			T* component = nullptr;
			for (Component* comp : mComponents)
			{
				if (comp->GetName() == compName)
				{
					component = dynamic_cast<T*>(comp);
					break;
				}
			}
			return component;
		}

	private:
		// void repositionWithinBounds();

		const Layer::eLayerType mLayerLevel;
		std::vector<Component*> mComponents;
	};
} // namespace hs