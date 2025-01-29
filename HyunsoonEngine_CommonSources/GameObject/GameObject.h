#pragma once

#include "../Input/Input.h"
#include "../MathTypes.h"
#include "../Component/Component.h"
#include "../Enums/Enums.h"

namespace hs
{
	class GameObject
	{
	public:
		GameObject();
		virtual ~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC& hdc);

		template <typename T>
		T* AddComponent()
		{
			T* component = new T();
			component->Initialize();
			component->SetOwner(this);
			mComponents.emplace_back(component);

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

		std::vector<Component*> mComponents;
	};
} // namespace hs