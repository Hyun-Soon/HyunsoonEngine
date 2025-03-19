#pragma once

#include "GdiPlusInclude.h"
#include "Scene/SceneManager.h"
#include "Input/Input.h"
#include "Resource/ResourceManager.h"
#include "../HyunsoonEngine_Window/Object/Player.h"

namespace hs
{
	class Application
	{
	public:
		Application();
		~Application();

		const Vector2& GetResolution();
		const HDC&	   GetHdc() const;
		const HWND&	   GetHwnd() const;

		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();
		void Release();

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

		Vector2 mResolution;
	};
} // namespace hs
