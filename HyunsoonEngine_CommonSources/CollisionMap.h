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
		bool CheckCollision(Vector2 pos) const;

	private:
		static std::wstring collisionMapPath;
		std::vector<bool>	collisionData; // true: 충돌, false: 이동 가능
	};
} // namespace hs
