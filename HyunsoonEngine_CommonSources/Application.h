#pragma once

#include <Windows.h>
#include <mmsystem.h>
#include <dinput.h>
#pragma comment(lib, "Msimg32.lib")
#pragma comment(lib, "winmm.lib")

#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")

#include "SceneManager.h"
#include "Input.h"

namespace hs
{
	struct Resolution
	{
		UINT width;
		UINT height;

		Resolution(UINT w, UINT h)
			: width(w), height(h) {};
	};

	class Application
	{
	public:
		Application();
		~Application();

		static const Resolution& GetResolution();

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
		HDC	 mHdc;

		HDC		mBackHdc;
		HBITMAP mBackBitmap;

		static Resolution mResolution;
	};
} // namespace hs
