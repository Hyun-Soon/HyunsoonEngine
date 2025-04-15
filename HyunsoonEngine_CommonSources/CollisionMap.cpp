#include "CollisionMap.h"

// debug
#include <cassert>

namespace hs
{
	std::wstring CollisionMap::collisionMapPath = L"../HyunsoonEngine_Window/MaplestoryResources/CollisionMaps/";

	CollisionMap::CollisionMap(std::wstring name)
		: graphics::Texture()
	{
		HRESULT result = Load((collisionMapPath + name + L".bmp").c_str());
		assert(result == S_OK);
		// ParseCollisionData();
	}

	CollisionMap::~CollisionMap()
	{
	}

	bool CollisionMap::ParseCollisionData()
	{
		const HDC& textureHdc = GetHdc();
		UINT	   width = GetResolution().x;
		UINT	   height = GetResolution().y;

		int sz = width * height;
		collisionData.resize(sz);

		for (int r = 0; r < height; r++)
		{
			for (int c = 0; c < width; c++)
			{

				COLORREF color = GetPixel(textureHdc, c, r);
				if (color == CLR_INVALID)
				{
					return false;
				}

				int	 red = GetRValue(color);
				int	 green = GetGValue(color);
				int	 blue = GetBValue(color);
				bool val;
				if (red == 255 && green == 0 && blue == 255)
					val = true;
				else
					val = false;

				int idx = r * width + c;
				collisionData[r * width + c] = val;
			}
		}

		Texture::Delete();

		return true;
	}

	bool CollisionMap::CheckCollision(Vector2 pos, const Vector2& size) const
	{
		int left = pos.x - size.x;
		int right = pos.x;
		int top = pos.y - size.y;
		int bottom = pos.y;

		if (left < 0 || top < 0)
			return true;

		// for (int r = top; r <= bottom; r++)
		//{
		//	for (int c = left; c <= right; c++)
		//	{
		//		COLORREF color = GetPixel(GetHdc(), c, r);
		//		if (GetRValue(color) == 255 && GetGValue(color) == 0 && GetBValue(color) == 255)
		//			return true;
		//	}
		// }

		/*COLORREF color1 = GetPixel(GetHdc(), left, top);
		if (GetRValue(color1) == 255 && GetGValue(color1) == 0 && GetBValue(color1) == 255)
			return true;
		COLORREF color2 = GetPixel(GetHdc(), right, top);
		if (GetRValue(color2) == 255 && GetGValue(color2) == 0 && GetBValue(color2) == 255)
			return true;*/
		COLORREF color3 = GetPixel(GetHdc(), left, bottom);
		if (GetRValue(color3) == 255 && GetGValue(color3) == 0 && GetBValue(color3) == 255)
			return true;
		COLORREF color4 = GetPixel(GetHdc(), right, bottom);
		if (GetRValue(color4) == 255 && GetGValue(color4) == 0 && GetBValue(color4) == 255)
			return true;

		return false;
	}

} // namespace hs
