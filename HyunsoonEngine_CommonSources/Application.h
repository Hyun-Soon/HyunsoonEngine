#pragma once

#include "SceneManager.h"
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
		void createBuffer(UINT width, UINT height);
		void clearRenderTarget();
		void present(HDC dst, HDC src);

		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;

	};
}
