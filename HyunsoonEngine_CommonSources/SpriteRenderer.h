#pragma once

#include <mmsystem.h>
#include <dinput.h>
#pragma comment(lib, "Msimg32.lib");
#pragma comment(lib, "winmm.lib");

#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib");

#include "Entity.h"
#include "Component.h"

namespace hs
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		virtual ~SpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC& hdc) override;

		void ImageLoad(const std::wstring& path);

	private:
		Gdiplus::Image* mImage;
		UINT			mWidth;
		UINT			mHeight;
	};
} // namespace hs