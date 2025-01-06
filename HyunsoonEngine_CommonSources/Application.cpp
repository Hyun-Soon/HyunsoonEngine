#include "Application.h"

namespace hs
{
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mBackHdc(NULL)
		, mBackBitmap(NULL)
		, mWidth(0)
		, mHeight(0)
	{

	}

	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);
		UpdateWindow(mHwnd);

		createBuffer(mWidth, mHeight);
		Input::Initialize();
		Time::Initialize();
		SceneManager::Initialize();
	}

	void Application::Run()
	{
		update();
		lateUpdate();
		render();
	}

	void Application::update()
	{
		Input::Update();
		Time::Update();
		SceneManager::Update();
	}

	void Application::lateUpdate()
	{

	}

	void Application::render()
	{
		clearRenderTarget();

		Time::Render(mBackHdc);
		SceneManager::Render(mBackHdc);

		present(mHdc, mBackHdc);
	}

	void Application::createBuffer(UINT width, UINT height)
	{
		//윈도우 해상도에 맞는 백버퍼(도화지)생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		//백버퍼를 가르킬 DC생성
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);
	}

	void Application::clearRenderTarget()
	{
		Rectangle(mBackHdc, 0, 0, 1600, 900);
	}

	void Application::present(HDC dst, HDC src)
	{
		BitBlt(dst, 0, 0, mWidth, mHeight, src, 0, 0, SRCCOPY);
	}
}

