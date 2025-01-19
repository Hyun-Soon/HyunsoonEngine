#pragma once

#include "Input.h"
#include "MathTypes.h"
#include "Component.h"

namespace hs
{
	class GameObject
	{
	public:
		GameObject(Vector2 pos);
		~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC& hdc);

		void		   SetPosition(float x, float y);
		const Vector2& GetPosition() const;

		template <typename T>
		T* AddComponent()
		{
			T* component = new T();
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
				component = dynamic_cast<T*>(comp);
				if (component)
					break;
			}
			return component;
		}

	protected:
		Vector2 mPos;

	private:
		void repositionWithinBounds();

		std::vector<Component*> mComponents;
	};
} // namespace hs