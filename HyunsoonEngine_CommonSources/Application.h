#pragma once

#include "GdiPlusInclude.h"
#include "Scene/SceneManager.h"
#include "Input/Input.h"
#include "GameObject/Player.h"

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
		const HDC&				 GetHdc() const;

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
