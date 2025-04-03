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
		ParseCollisionData();
	}

	CollisionMap::~CollisionMap()
	{
	}

	bool CollisionMap::ParseCollisionData()
	{
		const HDC& textureHdc = GetHdc();
		UINT	   width = GetWidth();
		UINT	   height = GetHeight();

		collisionData.resize(width * height);

		for (int r = 0; r < height; r++)
		{
			for (int c = 0; c < width; c++)
			{
				COLORREF color = GetPixel(textureHdc, r, c);
				if (color == CLR_INVALID) // TOOD :: error occured when r == 1
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

				collisionData[r * width + c] = val;

				if (val == true)
					OutputDebugString((L"pos : " + std::to_wstring(r) + L", " + std::to_wstring(c) + L"\n").c_str());
			}
		}

		// TODO :: release hdc and bitmap

		return true;
	}

	bool CollisionMap::CheckCollision(Vector2 pos) const

	{
		if (pos.x < 0 || pos.x >= GetWidth() || pos.y < 0 || pos.y >= GetHeight())
			return true; // 甘 观篮 面倒 贸府
		return collisionData[pos.y * GetWidth() + pos.x];
	}

} // namespace hs
