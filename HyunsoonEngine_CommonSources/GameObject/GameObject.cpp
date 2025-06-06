#include "GameObject/GameObject.h"
#include "Component/Transform.h"
#include "GameObject.h"

namespace hs
{
	namespace object
	{
		void Destroy(GameObject* gameObject)
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
		, mParent(nullptr)
		, mChilds(0)
	{
		initializeTransform();
	}

	GameObject::~GameObject()
	{
		if (mChilds.size())
		{
			for (GameObject*& child : mChilds)
			{
				delete child;
				child = nullptr;
			}
		}

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
		for (GameObject* child : mChilds)
			child->Update();

		for (Component* component : mComponents)
		{
			if (component == nullptr)
				continue;
			component->Update();
		}
	}

	void GameObject::LateUpdate()
	{
		for (GameObject* child : mChilds)
			child->LateUpdate();

		for (Component* component : mComponents)
		{
			if (component == nullptr)
				continue;
			component->LateUpdate();
		}
	}

	void GameObject::Render(HDC& hdc)
	{
		for (GameObject* child : mChilds)
			child->Render(hdc);

		for (Component* component : mComponents)
		{
			if (component == nullptr)
				continue;
			component->Render(hdc);
		}
	}

	void GameObject::AddChild(GameObject* child)
	{
		child->SetParent(this);
		mChilds.push_back(child);
	}

	void GameObject::initializeTransform()
	{
		AddComponent<Transform>();
	}

} // namespace hs
