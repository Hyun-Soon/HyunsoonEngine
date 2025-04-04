#include "Texture.h"
#include "Application.h"
#include "Resource/ResourceManager.h"

extern hs::Application app;

namespace hs
{
	namespace graphics
	{
		Texture::Texture()
			: Resource(enums::eResourceType::Texture)
			, mbAlpha(false)
		{
		}

		Texture::~Texture()
		{
		}

		Texture* Texture::Create(const std::wstring& name, UINT width, UINT height)
		{
			Texture* image = ResourceManager::Find<Texture>(name);
			if (image)
				return image;

			image = new Texture();
			image->SetName(name);
			image->SetWidth(width);
			image->SetHeight(height);

			HDC	 hdc = app.GetHdc();
			HWND hwnd = app.GetHwnd();

			image->mBitmap = CreateCompatibleBitmap(hdc, width, height);
			image->mHdc = CreateCompatibleDC(hdc);

			HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
			HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);
			Rectangle(image->mHdc, -1, -1, image->GetWidth() + 1, image->GetHeight() + 1);
			SelectObject(hdc, oldBrush);

			HBITMAP oldBitmap = (HBITMAP)SelectObject(image->mHdc, image->mBitmap);
			DeleteObject(oldBitmap);

			ResourceManager::Insert(name + L"Image", image);

			return image;
		}

		HRESULT Texture::Load(const std::wstring& path)
		{
			std::wstring ext = path.substr(path.find_last_of(L".") + 1);

			if (ext == L"bmp")
			{
				mType = eTextureType::Bmp;
				mBitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

				BITMAP info = {};
				GetObject(mBitmap, sizeof(BITMAP), &info);

				if (mBitmap == nullptr)
				{
					return S_FALSE;
				}

				mWidth = info.bmWidth;
				mHeight = info.bmHeight;

				if (info.bmBitsPixel == 32)
					mbAlpha = true;
				else if (info.bmBitsPixel == 24)
					mbAlpha = false;

				HDC mainDC = app.GetHdc();
				mHdc = CreateCompatibleDC(mainDC);

				HBITMAP oldBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);
				DeleteObject(oldBitmap);
			}
			else if (ext == L"png")
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

			return S_OK;
		}
	} // namespace graphics

} // namespace hs
