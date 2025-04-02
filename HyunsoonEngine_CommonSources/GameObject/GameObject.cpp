#include "GameObject/GameObject.h"
#include "Component/Transform.h"

namespace hs
{
	namespace object
	{
		void Destory(GameObject* gameObject)
		{
			if (gameObject == nullptr)
				return;
			gameObject->death();
		}
	} // namespace object

	GameObject::GameObject()
		: mState(GameObject::eGameObjectState::Active)
		, mComponents((UINT)enums::eComponentType::End, nullptr)
		, mLayerType(enums::eLayerType::None)
	{
		initializeTransform();
	}

	GameObject::~GameObject()
	{
		for (Component*& component : mComponents)
		{
			delete component;
			component = nullptr;
		}
	}

	void GameObject::Initialize()
	{
		for (Component* component : mComponents)
		{
			if (component == nullptr)
				continue;
			component->Initialize();
		}
	}

	void GameObject::Update()
	{
		for (Component* component : mComponents)
		{
			if (component == nullptr)
				continue;
			component->Update();
		}
	}

	void GameObject::LateUpdate()
	{
		for (Component* component : mComponents)
		{
			if (component == nullptr)
				continue;
			component->LateUpdate();
		}
	}

	void GameObject::Render(HDC& hdc)
	{
		for (Component* component : mComponents)
		{
			if (component == nullptr)
				continue;
			component->Render(hdc);
		}
	}

	void GameObject::initializeTransform()
	{
		AddComponent<Transform>();
	}

} // namespace hs
