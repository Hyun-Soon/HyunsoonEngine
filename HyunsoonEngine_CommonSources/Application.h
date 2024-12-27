#pragma once

#include "GameObject.h"
#include "Input.h"

namespace hs
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();

	private:
		void update();
		void lateUpdate();
		void render();

		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;

		GameObject mSquare;
	};
}
