#include "Application.h"
#include "Resource/ResourceManager.h"
#include "CollisionManager.h"
#include "UI/UIManager.h"

#include <cassert>

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

	const HWND& Application::GetHwnd() const
	{
		return mHwnd;
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
		CollisionManager::Initialize();
		SceneManager::Initialize();
		UIManager::Initialize();
	}

	void Application::Run()
	{
		update();
		lateUpdate();
		render();
		destroy();
	}

	void Application::update()
	{
		Input::Update();
		TimeUtils::Update();
		CollisionManager::Update();
		SceneManager::Update();
		UIManager::Update();
	}

	void Application::lateUpdate()
	{
		CollisionManager::LateUpdate();
		SceneManager::LateUpdate();
		UIManager::LateUpdate();
	}

	void Application::render()
	{
		clearRenderTarget();

		TimeUtils::Render(mBackHdc);
		// CollisionManager::Render(mBackHdc);
		SceneManager::Render(mBackHdc);
		UIManager::Render(mBackHdc);

		present(mHdc, mBackHdc);
	}

	void Application::destroy()
	{
		SceneManager::Destroy();
	}

	void Application::Release()
	{
		SceneManager::Release();
		ResourceManager::Release();
		UIManager::Release();
	}

	void Application::createBuffer(UINT width, UINT height)
	{
		// ������ �ػ󵵿� �´� �����(��ȭ��)����
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		// ����۸� ����ų DC����
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);
	}

	void Application::clearRenderTarget()
	{
		HBRUSH backgroundBrush = (HBRUSH)CreateSolidBrush(RGB(255, 255, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(mBackHdc, backgroundBrush);

		Rectangle(mBackHdc, 0, 0, mResolution.x, mResolution.y);

		(HBRUSH) SelectObject(mBackHdc, oldBrush);
		DeleteObject(backgroundBrush);
	}

	void Application::present(HDC dst, HDC src)
	{
		BitBlt(dst, 0, 0, mResolution.x, mResolution.y, src, 0, 0, SRCCOPY);
		//	StretchBlt(dst,	   // ����� DC (������ ȭ��)
		//		0, 0,		   // ����� ��ġ (������ �»��)
		//		mResolution.x, // ����� �ʺ� (������ �ʺ�)
		//		mResolution.y, // ����� ���� (������ ����)
		//		src,		   // ���� �̹��� DC
		//		0, 0,		   // ���� �̹������� ������ �κ��� �»�� ��ǥ
		//		1500, 800,	   // ������ �κ��� ũ��
		//		SRCCOPY);
	}
} // namespace hs
