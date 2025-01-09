#include "Application.h"

namespace hs
{
	GameObject::GameObject()
		: mPos(0.0f, 0.0f), mSpeed(200.0f)
	{
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{
		repositionWithinBounds();
	}

	void GameObject::LateUpdate()
	{
	}

	void GameObject::Render(HDC& hdc)
	{

	}

	void GameObject::SetPosition(float x, float y)
	{
		mPos.x = x;
		mPos.y = y;

		return;
	}

	const float GameObject::GetPositionX() const
	{
		return mPos.x;
	}

	const float GameObject::GetPositionY() const
	{
		return mPos.y;
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
		else if (mPos.y > res.height)
			mPos.y = res.height;
	}
}



