#include "Transform.h"
#include "GameObject/GameObject.h"
#include "Animator.h"

namespace hs
{
	Transform::Transform()
		: Component(enums::eComponentType::Transform)
		, mScale(Vector2::One)
		, mRotation(0.0f)
		, mPrevPos(Vector2::Zero)
	{
	}

	Transform::~Transform()
	{
	}

	void Transform::Update()
	{
		mPrevPos = mPosition;
	}

	void Transform::RevertToPrevPos()
	{
		mPosition = mPrevPos;
	}

	const Vector2 Transform::GetCenterPosition() const
	{
		Animator* animator = GetOwner()->GetComponent<Animator>();
		if (animator)
		{
			return mPosition + animator->GetCenterOffset();
		}
		return mPosition;
	}

} // namespace hs
