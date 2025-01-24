#include "Application.h"

namespace hs
{
	Resolution Application::mResolution(0, 0);

	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mBackHdc(NULL)
		, mBackBitmap(NULL)
	{
	}

	Application::~Application()
	{
	}

	const Resolution& Application::GetResolution()
	{
		return mResolution;
	}

	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mResolution.width = rect.right - rect.left;
		mResolution.height = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mResolution.width, mResolution.height, 0);
		ShowWindow(mHwnd, true);
		UpdateWindow(mHwnd);

		createBuffer(mResolution.width, mResolution.height);
		Input::Initialize();
		TimeUtils::Initialize();
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
		TimeUtils::Update();
		SceneManager::Update();
	}

	void Application::lateUpdate()
	{
	}

	void Application::render()
	{
		clearRenderTarget();

		TimeUtils::Render(mBackHdc);
		SceneManager::Render(mBackHdc);

		present(mHdc, mBackHdc);
	}

	void Application::createBuffer(UINT width, UINT height)
	{
		// 윈도우 해상도에 맞는 백버퍼(도화지)생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		// 백버퍼를 가르킬 DC생성
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
		BitBlt(dst, 0, 0, mResolution.width, mResolution.height, src, 0, 0, SRCCOPY);
	}
} // namespace hs
