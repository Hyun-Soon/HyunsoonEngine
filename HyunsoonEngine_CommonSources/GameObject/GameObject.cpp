#include "GameObject/GameObject.h"
#include "Component/Transform.h"

namespace hs
{
	GameObject::GameObject(enums::eLayerType type)
		: mLayerLevel(type)
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
			component->Initialize();
		}
	}

	void GameObject::Update()
	{
		for (Component* component : mComponents)
		{
			component->Update();
		}
		// repositionWithinBounds();
	}

	void GameObject::LateUpdate()
	{
		for (Component* component : mComponents)
		{
			component->LateUpdate();
		}
	}

	void GameObject::Render(HDC& hdc)
	{
		for (Component* component : mComponents)
		{
			component->Render(hdc);
		}
	}

	const enums::eLayerType GameObject::GetLayerLevel() const
	{
		return mLayerLevel;
	}

	void GameObject::initializeTransform()
	{
		AddComponent<Transform>();
	}

	// void GameObject::repositionWithinBounds()
	//{
	//	Resolution res = Application::GetResolution();

	//	if (mPos.x < 0.0f)
	//		mPos.x = 0.0f;
	//	else if (mPos.x > res.width)
	//		mPos.x = res.width;

	//	if (mPos.y < 0.0f)
	//		mPos.y = 0.0f;
	//	else if (mPos.y > 600.0f) // temp
	//		mPos.y = 600.0f;
	//}
} // namespace hs
