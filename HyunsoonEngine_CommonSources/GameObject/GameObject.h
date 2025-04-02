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

		eGameObjectState GetState() const { return mState; }

		void SetActive(bool power)
		{
			if (power == true)
				mState = eGameObjectState::Active;
			else
				mState = eGameObjectState::Paused;
		}

		bool			  IsActive() const { return mState == eGameObjectState::Active; }
		bool			  IsDead() const { return mState == eGameObjectState::Dead; }
		void			  SetLayerType(enums::eLayerType layerType) { mLayerType = layerType; }
		enums::eLayerType GetLayerType() const { return mLayerType; }

	private:
		void initializeTransform();
		void death() { mState = eGameObjectState::Dead; }

		eGameObjectState		mState;
		std::vector<Component*> mComponents;
		enums::eLayerType		mLayerType;
	};
} // namespace hs