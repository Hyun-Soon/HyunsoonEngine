#pragma once

#include "../Input/Input.h"
#include "../MathTypes.h"
#include "../Component/Component.h"
#include "../Enums/Enums.h"

namespace hs
{
	namespace object
	{
		void Destory(GameObject* gameObject);
	}

	class GameObject
	{
	public:
		friend void object::Destory(GameObject* obj);

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

		eGameObjectState GetState() { return mState; }

		void SetActive(bool power)
		{
			if (power == true)
				mState = eGameObjectState::Active;
			else
				mState = eGameObjectState::Paused;
		}

		bool IsActive() { return mState == eGameObjectState::Active; }
		bool IsDead() { return mState == eGameObjectState::Dead; }
		// void Death() { mState = eGameObjectState::Dead; }

	private:
		void initializeTransform();
		void death() { mState = eGameObjectState::Dead; }

		eGameObjectState		mState;
		std::vector<Component*> mComponents;
	};
} // namespace hs