#include "Application.h"

namespace hs
{
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
	{

	}

	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		Input::Initialize();
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
		mSquare.Update();

	}

	void Application::lateUpdate()
	{

	}

	void Application::render()
	{
		mSquare.Render(mHdc);
	}
}