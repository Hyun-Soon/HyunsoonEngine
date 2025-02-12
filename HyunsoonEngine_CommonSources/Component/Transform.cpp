#include "Transform.h"

namespace hs
{
	Transform::Transform()
		: Component(enums::eComponentType::Transform)
		, mScale(Vector2::One)
		, mRotation(0.0f)
	{
	}

	Transform::~Transform()
	{
	}

} // namespace hs
