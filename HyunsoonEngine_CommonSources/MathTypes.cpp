#include "MathTypes.h"

namespace hs
{
	Vector2 Vector2::Zero = { 0.0f, 0.0f };
	Vector2 Vector2::One = { 1.0f, 1.0f };
	Vector2 Vector2::Left = { -1.0f, 0.0f };
	Vector2 Vector2::Right = { 1.0f, 0.0f };
	Vector2 Vector2::Up = { 0.0f, -1.0f };
	Vector2 Vector2::Down = { 0.0f, 1.0f };

	static float ConvertRadianToDegree(float radian)
	{
		return (radian * (180 / PI));
	}

} // namespace hs
