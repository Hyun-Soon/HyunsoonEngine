#include "Application.h"

namespace hs
{
	GameObject::GameObject(Vector2 pos)
		: mPos(pos)
	{
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
		repositionWithinBounds();
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

	void GameObject::SetPosition(float x, float y)
	{
		mPos.x = x;
		mPos.y = y;

		return;
	}

	const Vector2& GameObject::GetPosition() const
	{
		return mPos;
	}

	void GameObject::repositionWithinBounds()
	{
		Resolution res = Application::GetResolution();

		if (mPos.x < 0.0f)
			mPos.x = 0.0f;
		else if (mPos.x > res.width)
			mPos.x = res.width;

		if (mPos.y < 0.0f)
			mPos.y = 0.0f;
		else if (mPos.y > 600.0f) // temp //question : how to determine
			mPos.y = 600.0f;
	}
} // namespace hs
