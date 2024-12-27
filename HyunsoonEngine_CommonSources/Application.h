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

		void Update();
		void LateUpdate();
		void Render();


	private:
		HWND mHwnd;
		HDC mHdc;

		GameObject mSquare;
	};
}
