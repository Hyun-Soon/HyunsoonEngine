#pragma once

#include <vector>

#include "MathTypes.h"
#include "Resource/Texture.h"

namespace hs
{
	class CollisionMap : public graphics::Texture
	{
	public:
		CollisionMap(std::wstring name);
		virtual ~CollisionMap();

		bool ParseCollisionData();
		bool CheckCollision(Vector2 pos, const Vector2& size) const;

		std::vector<bool> collisionData; // true: �浹, false: �̵� ����

	private:
		static std::wstring collisionMapPath;
	};
} // namespace hs
