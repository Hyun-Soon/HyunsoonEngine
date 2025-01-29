#pragma once

#include <cmath>

namespace hs
{
	struct Vector2
	{
		static Vector2 Zero;
		static Vector2 One;

		float x;
		float y;

		Vector2()
			: x(0.0f), y(0.0f) {}

		Vector2(float x, float y)
			: x(x), y(y) {}

		inline float Magnitude() const
		{
			return sqrt(x * x + y * y);
		}

		inline Vector2 Normalize()
		{
			float mag = Magnitude();
			x /= mag;
			y /= mag;
			return *this;
		}

		inline static float Length(Vector2& lhs, Vector2& rhs)
		{
			return sqrt((rhs.x - lhs.x) * (rhs.x - lhs.x) + (rhs.y - lhs.y) * (rhs.y - lhs.y));
		}

		inline Vector2 operator+(const Vector2& other) const
		{
			return Vector2(this->x + other.x, this->y + other.y);
		}

		inline Vector2 operator-(const Vector2& other) const
		{
			return Vector2(this->x - other.x, this->y - other.y);
		}

		inline Vector2 operator*(const float operand) const
		{
			return Vector2(this->x * operand, this->y * operand);
		}

		inline const Vector2 operator+=(const Vector2& other)
		{
			this->x += other.x;
			this->y += other.y;
			return *this;
		}

		inline Vector2 operator-() const
		{
			return Vector2(this->x * -1, this->y * -1);
		}
	};
} // namespace hs
