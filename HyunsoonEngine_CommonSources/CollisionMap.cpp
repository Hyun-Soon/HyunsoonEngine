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

	bool CollisionMap::CheckCollision(Vector2 pos) const

	{
		if (pos.x < 0 || pos.x >= GetResolution().x || pos.y < 0 || pos.y >= GetResolution().y)
			return true;
		COLORREF color = GetPixel(GetHdc(), pos.x, pos.y);
		if (GetRValue(color) == 255 && GetGValue(color) == 0 && GetBValue(color) == 255)
			return true;
		return false;
		// return collisionData[pos.y * GetResolution().x + pos.x];
	}

} // namespace hs
