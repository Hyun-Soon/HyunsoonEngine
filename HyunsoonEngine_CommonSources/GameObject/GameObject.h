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
		enum class eGameObjectState
		{
			Active,
			Paused,
			Dead,
			End
		};

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
			component->SetOwner(this);
			component->Initialize();
			mComponents[(UINT)component->GetType()] = component;

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

		eGameObjectState GetActive() { return mState; }

		void SetActive(bool power)
		{
			if (power == true)
				mState = eGameObjectState::Active;
			else
				mState = eGameObjectState::Paused;
		}

		void Death() { mState = eGameObjectState::Dead; }

	private:
		void initializeTransform();

		eGameObjectState		mState;
		std::vector<Component*> mComponents;
	};
} // namespace hs