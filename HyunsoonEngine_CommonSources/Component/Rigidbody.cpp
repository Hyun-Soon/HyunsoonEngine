#include "TimeUtils.h"
#include "GameObject/GameObject.h"
#include "Rigidbody.h"

namespace hs
{

	Rigidbody::Rigidbody()
		: Component(enums::eComponentType::Rigidbody)
		, mTransform(nullptr)
		, mMass(1.0f)
		, mVel(Vector2::Zero)
		, mAcc(Vector2::Zero)
		, mbUseGravity(false)
		, mbIsKinematic(false)
	{
	}

	Rigidbody::~Rigidbody()
	{
	}

	void Rigidbody::Initialize()
	{
		mTransform = GetOwner()->GetComponent<Transform>();
	}

	void Rigidbody::Update()
	{
		if (mTransform == nullptr)
			return;

		float dt = TimeUtils::GetDeltaTime();
		float dt2 = dt * dt;

		if (mbUseGravity)
			AddAcceleration({ 0.0f, 98.0f });

		if (isGrounded() && mVel.y > 0.0f)
		{
			mVel.y = 0.0f;
			mAcc.y = 0.0f;
		}

		Vector2 position = mTransform->GetPosition();
		position += mVel * dt + mAcc * dt2 * 0.5f;
		mVel += mAcc * dt;
		mTransform->SetPosition(position);
	}

	void Rigidbody::LateUpdate()
	{
	}

	void Rigidbody::SetVelocity(Vector2 vel)
	{
		mVel = vel;
	}

	void Rigidbody::SetAcceleration(Vector2 acc)
	{
		mAcc = acc;
	}

	void Rigidbody::SetGravity(bool enable)
	{
		mbUseGravity = enable;
	}

	void Rigidbody::SetKinematic(bool enable)
	{
		mbIsKinematic = enable;
	}

	void Rigidbody::AddVelocity(Vector2 vel)
	{
		mVel += vel;
	}

	void Rigidbody::AddAcceleration(Vector2 acc)
	{
		mAcc += acc;
	}

	void Rigidbody::AddForce(Vector2 force)
	{
		AddAcceleration(force / mMass);
	}
	bool Rigidbody::isGrounded()
	{
		return (mTransform->GetPosition().y >= 600.0f);
	}
} // namespace hs