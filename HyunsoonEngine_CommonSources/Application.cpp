#include "Application.h"

namespace hs
{
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mBackHdc(NULL)
		, mBackBitmap(NULL)
		, mResolution(0, 0)
	{
	}

	Application::~Application()
	{
	}

	const Vector2& Application::GetResolution()
	{
		return mResolution;
	}

	const HDC& Application::GetHdc() const
	{
		return mHdc;
	}

	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mResolution.x = rect.right - rect.left;
		mResolution.y = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mResolution.x, mResolution.y, 0);
		ShowWindow(mHwnd, true);
		UpdateWindow(mHwnd);

		createBuffer(mResolution.x, mResolution.y);
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
		SceneManager::LateUpdate();
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
		BitBlt(dst, 0, 0, mResolution.x, mResolution.y, src, 0, 0, SRCCOPY);
	}
} // namespace hs
