#pragma once

#include "../Input/Input.h"
#include "../MathTypes.h"
#include "../Component/Component.h"
#include "../Enums/Enums.h"

namespace hs
{
	namespace object
	{
		void Destroy(GameObject* gameObject);
	}

	class GameObject
	{
	public:
		friend void object::Destroy(GameObject* obj);

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

		void AddChild(GameObject* child);
		bool HasChild() { return mChilds.size(); }
		std::vector<GameObject*>& GetChilds() { return mChilds; }

		bool			  IsActive() const { return mState == eGameObjectState::Active; }
		bool			  IsDead() const { return mState == eGameObjectState::Dead; }

		void			  SetParent(GameObject* parent) { mParent = parent; }
		GameObject*		  GetParent() const { return mParent; }
		void			  SetLayerType(enums::eLayerType layerType) { mLayerType = layerType; }
		enums::eLayerType GetLayerType() const { return mLayerType; }

	private:
		void initializeTransform();
		void death() { mState = eGameObjectState::Dead; }

		eGameObjectState		 mState;
		std::vector<Component*>  mComponents;
		enums::eLayerType		 mLayerType;
		GameObject*				 mParent;
		std::vector<GameObject*> mChilds;
	};
} // namespace hs