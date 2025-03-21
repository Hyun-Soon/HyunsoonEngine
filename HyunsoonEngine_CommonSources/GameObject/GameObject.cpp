#include "GameObject/GameObject.h"
#include "Component/Transform.h"

namespace hs
{
	GameObject::GameObject()
		: mComponents((UINT)enums::eComponentType::End, nullptr)
		, mState(GameObject::eGameObjectState::Active)
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
		// repositionWithinBounds();
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
