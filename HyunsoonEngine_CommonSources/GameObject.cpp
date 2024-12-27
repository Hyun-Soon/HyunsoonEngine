#include "GameObject.h"

namespace hs
{
	GameObject::GameObject()
		: mX(0.0f), mY(0.0f), mSpeed(100.0f)
	{
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{
		if (Input::GetKey(eKeyCode::A))
		{
			mX -= mSpeed * Time::GetDeltaTime();
		}

		if (Input::GetKey(eKeyCode::D))
		{
			mX += mSpeed * Time::GetDeltaTime();
		}

		if (Input::GetKey(eKeyCode::W))
		{
			mY -= mSpeed * Time::GetDeltaTime();
		}

		if (Input::GetKey(eKeyCode::S))
		{
			mY += mSpeed * Time::GetDeltaTime();
		}
	}

	void GameObject::LateUpdate()
	{
	}

	void GameObject::Render(HDC& hdc)
	{
		int color = RGB(int(mX * 3) % 256, int(mX * 6) % 256, int(mY * 9) % 256);
		HBRUSH newBrush = CreateSolidBrush(color);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, newBrush);

		HPEN newPen = CreatePen(PS_SOLID, 2, color);
		HPEN oldPen = (HPEN)SelectObject(hdc, newPen);

		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		SelectObject(hdc, oldBrush);
		SelectObject(hdc, oldPen);
		DeleteObject(newBrush);
		DeleteObject(newPen);
	}

	void GameObject::SetPosition(float x, float y)
	{
		mX = x;
		mY = y;

		return;
	}

	const float GameObject::GetPositionX() const
	{
		return mX;
	}

	const float GameObject::GetPositionY() const
	{
		return mY;
	}
}



