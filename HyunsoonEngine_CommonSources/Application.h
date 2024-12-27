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

		void Initialize(HWND hwnd);
		void Run();

	private:
		void update();
		void lateUpdate();
		void render();

		HWND mHwnd;
		HDC mHdc;

		GameObject mSquare;
	};
}
