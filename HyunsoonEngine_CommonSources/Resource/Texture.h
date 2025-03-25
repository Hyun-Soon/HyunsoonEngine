#pragma once

#include "../GdiPlusInclude.h"
#include "../Resource/Resource.h"

namespace hs
{
	namespace graphics
	{
		class Texture : public Resource
		{
		public:
			enum class eTextureType
			{
				Bmp,
				Png,
				None,
			};

			Texture();
			~Texture();

			static Texture* Create(const std::wstring& name, UINT width, UINT height);

			virtual HRESULT Load(const std::wstring& path) override;

			UINT			GetWidth() const { return mWidth; }
			void			SetWidth(UINT width) { mWidth = width; }
			UINT			GetHeight() const { return mHeight; }
			void			SetHeight(UINT height) { mHeight = height; }
			HDC				GetHdc() const { return mHdc; }
			eTextureType	GetTextureType() const { return mType; }
			Gdiplus::Image* GetImage() const { return mImage; }
			bool			IsAlpha() { return mbAlpha; }

		private:
			bool			mbAlpha;
			eTextureType	mType;
			Gdiplus::Image* mImage;
			HBITMAP			mBitmap;
			HDC				mHdc;

			UINT mWidth;
			UINT mHeight;
		};
	} // namespace graphics
} // namespace hs
