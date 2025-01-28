#pragma once

#include "Input/Input.h"
#include "MathTypes.h"
#include "Component/SpriteRenderer.h"
#include "Enums/Enums.h"

namespace hs
{
	class GameObject
	{
	public:
		GameObject(enums::eLayerType type);
		virtual ~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC& hdc);

		const enum class enums::eLayerType GetLayerLevel() const;

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

		const enums::eLayerType mLayerLevel;
		std::vector<Component*> mComponents;
	};
} // namespace hs