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
		int color = RGB(int(mPos.x * 3) % 256, int(mPos.x * 6) % 256, int(mPos.y * 9) % 256);
		HBRUSH newBrush = CreateSolidBrush(color);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, newBrush);

		HPEN newPen = CreatePen(PS_SOLID, 2, color);
		HPEN oldPen = (HPEN)SelectObject(hdc, newPen);

		Rectangle(hdc, 100 + mPos.x, 100 + mPos.y, 200 + mPos.x, 200 + mPos.y);

		SelectObject(hdc, oldBrush);
		SelectObject(hdc, oldPen);
		DeleteObject(newBrush);
		DeleteObject(newPen);
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



