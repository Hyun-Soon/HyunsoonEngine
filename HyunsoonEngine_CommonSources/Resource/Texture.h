#pragma once

#include "../GdiPlusInclude.h"
#include "../Resource/Resource.h"
#include "../MathTypes.h"

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

			void Delete();

			Vector2			GetResolution() const { return mResolution; }
			void			SetResolution(Vector2 res) { mResolution = res; }
			const HDC&		GetHdc() const { return mHdc; }
			eTextureType	GetTextureType() const { return mType; }
			Gdiplus::Image* GetImage() const { return mImage; }
			bool			IsAlpha() { return mbAlpha; }

		private:
			bool			mbAlpha;
			eTextureType	mType;
			Gdiplus::Image* mImage;
			HBITMAP			mBitmap;
			HDC				mHdc;

			Vector2 mResolution;
		};
	} // namespace graphics
} // namespace hs
