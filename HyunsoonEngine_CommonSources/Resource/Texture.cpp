#include "Texture.h"
#include "Application.h"

extern hs::Application app;

namespace hs
{
	namespace graphics
	{
		Texture::Texture()
			: Resource(enums::eResourceType::Texture)
		{
		}

		Texture::~Texture()
		{
		}

		HRESULT Texture::Load(const std::wstring& path)
		{
			std::wstring ext = path.substr(path.find_last_of(L".") + 1);

			if (ext == L"png")
			{
				mType = eTextureType::Png;
				mImage = Gdiplus::Image::FromFile(path.c_str());

				if (mImage == nullptr)
					return S_FALSE;

				mWidth = mImage->GetWidth();
				mHeight = mImage->GetHeight();

				HDC mainDC = app.GetHdc();
				mHdc = CreateCompatibleDC(mainDC);

				HBITMAP hBitmap = CreateCompatibleBitmap(mainDC, mWidth, mHeight);
				SelectObject(mHdc, hBitmap);

				Gdiplus::Graphics graphics(mHdc);
				graphics.DrawImage(mImage, Gdiplus::Rect(0, 0, mWidth, mHeight));
			}
			else if (ext == L"bmp")
			{
				mType = eTextureType::Bmp;
				mBitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
				// DWORD		 error = GetLastError();
				// std::wstring msg = L"Debug Value: " + std::to_wstring(error) + L"\n";
				// OutputDebugString(msg.c_str());

				BITMAP info = {};
				GetObject(mBitmap, sizeof(BITMAP), &info);

				if (mBitmap == nullptr)
				{
					return S_FALSE;
				}

				mWidth = info.bmWidth;
				mHeight = info.bmHeight;

				HDC mainDC = app.GetHdc();
				mHdc = CreateCompatibleDC(mainDC);

				HBITMAP oldBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);
				DeleteObject(oldBitmap);
			}

			return S_OK;
		}
	} // namespace graphics

} // namespace hs
