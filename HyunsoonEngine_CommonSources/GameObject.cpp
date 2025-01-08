#include "GameObject.h"

namespace hs
{
	GameObject::GameObject()
		: mPos(0.0f, 0.0f), mSpeed(100.0f)
	{
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{
		if (Input::GetKey(eKeyCode::A))
		{
			mPos.x -= mSpeed * Time::GetDeltaTime();
		}

		if (Input::GetKey(eKeyCode::D))
		{
			mPos.x += mSpeed * Time::GetDeltaTime();
		}

		if (Input::GetKey(eKeyCode::W))
		{
			mPos.y -= mSpeed * Time::GetDeltaTime();
		}

		if (Input::GetKey(eKeyCode::S))
		{
			mPos.y += mSpeed * Time::GetDeltaTime();
		}
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
}



