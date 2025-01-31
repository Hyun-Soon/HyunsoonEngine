#include "Transform.h"

namespace hs
{
	Transform::Transform()
		: Component(enums::eComponentType::Transform)
	{
	}

	Transform::~Transform()
	{
	}

	void Transform::SetPosition(Vector2& pos)
	{
		mPosition = pos;
	}

	const Vector2& Transform::GetPosition() const
	{
		return mPosition;
	}

} // namespace hs
