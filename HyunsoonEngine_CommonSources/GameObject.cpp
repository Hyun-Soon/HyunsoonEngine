#include "GameObject.h"

hs::GameObject::GameObject()
	: mX(0.0f), mY(0.0f)
{
}

hs::GameObject::~GameObject()
{
}

void hs::GameObject::Update()
{
	if (Input::GetKey(eKeyCode::A))
	{
		mX -= 0.01f;
	}

	if (Input::GetKey(eKeyCode::D))
	{
		mX += 0.01f;
	}

	if (Input::GetKey(eKeyCode::W))
	{
		mY -= 0.01f;
	}

	if (Input::GetKey(eKeyCode::S))
	{
		mY += 0.01f;
	}
}

void hs::GameObject::LateUpdate()
{
}

void hs::GameObject::Render(HDC& hdc)
{
	auto color = RGB(int(mX * 3) % 256, int(mX * 6) % 256, int(mX * 9) % 256);
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

void hs::GameObject::SetPosition(float x, float y)
{
	mX = x;
	mY = y;

	return;
}

const float hs::GameObject::GetPositionX() const
{
	return mX;
}

const float hs::GameObject::GetPositionY() const
{
	return mY;
}


