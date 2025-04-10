#pragma once

#include <cmath>

namespace hs
{
#define PI 3.141592f

	static float ConvertRadianToDegree(float radian);

	struct Vector2
	{
		static Vector2 Zero;
		static Vector2 One;
		static Vector2 Left;
		static Vector2 Right;
		static Vector2 Up;
		static Vector2 Down;

		float x;
		float y;

		Vector2()
			: x(0.0f), y(0.0f) {}

		Vector2(float x, float y)
			: x(x), y(y) {}

		inline float Length() const
		{
			return sqrtf(x * x + y * y);
		}

		inline Vector2 Normalize()
		{
			float mag = Length();
			x /= mag;
			y /= mag;
			return *this;
		}

		inline static float Length(const Vector2& lhs, const Vector2& rhs)
		{
			return sqrt((rhs.x - lhs.x) * (rhs.x - lhs.x) + (rhs.y - lhs.y) * (rhs.y - lhs.y));
		}

		Vector2 Rotate(Vector2 vector, float degree)
		{
			float radian = (degree / 180.f) * PI;
			vector.Normalize();
			float x = cosf(radian) * vector.x - sinf(radian) * vector.y;
			float y = sinf(radian) * vector.x + cosf(radian) * vector.y;

			return Vector2(x, y);
		}

		float Dot(Vector2& v1, Vector2& v2)
		{
			return v1.x * v2.x + v1.y * v2.y;
		}

		float Cross(Vector2& v1, Vector2& v2)
		{
			return v1.x * v2.y - v1.y * v2.x;
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

		inline Vector2 operator*(const Vector2& other) const
		{
			return Vector2(this->x * other.x, this->y * other.y);
		}

		inline Vector2 operator/(const float operand) const
		{
			return Vector2(this->x / operand, this->y / operand);
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

		inline bool operator==(const Vector2& other) const
		{
			return (this->x == other.x && this->y == other.y);
		}

		inline const Vector2 operator*=(const float operand)
		{
			this->x *= operand;
			this->y *= operand;
			return Vector2(this->x, this->y);
		}
	};
}; // namespace hs