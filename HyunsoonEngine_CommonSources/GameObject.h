#pragma once

#include "Input.h"
#include "MathTypes.h"
#include "SpriteRenderer.h"
// #include "Component/Component.h"
#include "LayerTypes.h"

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

		const eLayerType		mLayerLevel;
		std::vector<Component*> mComponents;
	};
} // namespace hs