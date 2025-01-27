#include "Component/Physics.h"
#include "TimeUtils.h"
#include "GameObject/GameObject.h"

namespace hs
{
	Physics::Physics()
	{
	}

	Physics::~Physics()
	{
	}

	void Physics::Initialize()
	{
		mTransform = GetOwner()->GetComponent<Transform>();
	}

	void Physics::Update()
	{
		if (mTransform == nullptr)
			return;

		float dt = TimeUtils::GetDeltaTime();
		float dt2 = dt * dt;

		Vector2 position = mTransform->GetPosition();
		position += mVel * dt + mAcc * dt2;
		mVel += mAcc * dt;
		mTransform->SetPosition(position);
	}

	void Physics::LateUpdate()
	{
	}

	void Physics::SetVelocity(Vector2& vel)
	{
		mVel = vel;
	}

	void Physics::SetAcceleration(Vector2& acc)
	{
		mAcc = acc;
	}

	void Physics::AddVelocity(Vector2& vel)
	{
		mVel += vel;
	}

	void Physics::AddAcceleration(Vector2& acc)
	{
		mAcc += acc;
	}
} // namespace hs