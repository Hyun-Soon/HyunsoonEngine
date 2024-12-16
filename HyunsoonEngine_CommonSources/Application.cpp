#include "Application.h"

namespace hs
{
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mSpeed(0.0f)
		, mX(0.0f)
		, mY(0.0f)
	{

	}
	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	void Application::Update()
	{
		mSpeed += 0.01f;

		// 내가 오른쪾 키를 입력받았다면
		// x 좌표가 플러스
		// 왼쪽 -> x 가 마이너스
		// 위아래는 y가 플러스 마이너스
		if (GetAsyncKeyState(VK_LEFT))
		{
			mX -= 0.01f;
		}

		if (GetAsyncKeyState(VK_RIGHT))
		{
			mX += 0.01f;
		}

		if (GetAsyncKeyState(VK_UP))
		{
			mY -= 0.01f;
		}

		if (GetAsyncKeyState(VK_DOWN))
		{
			mY += 0.01f;
		}
	}
	void Application::LateUpdate()
	{

	}
	void Application::Render()
	{
		auto color = RGB(int(mSpeed * 3) % 255, int(mSpeed * 6) % 255, int(mSpeed * 9) % 255);
		HBRUSH newBrush = CreateSolidBrush(color);
		HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, newBrush);

		HPEN newPen = CreatePen(PS_SOLID, 2, color);
		HPEN oldPen = (HPEN)SelectObject(mHdc, newPen);

		Rectangle(mHdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		SelectObject(mHdc, oldBrush);
		SelectObject(mHdc, oldPen);
		DeleteObject(newBrush);
		DeleteObject(newPen);
	}
}