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
		, mbGrounded(false)
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
			AddAcceleration({ 0.0f, 120.0f });

		if (IsGrounded() && mVel.y > 0.0f)
		{
			mVel.y = 0.0f;
			mAcc.y = 0.0f;
		}

		Vector2 position = mTransform->GetPosition();
		position += mVel * dt + mAcc * dt2 * 0.5f;
		mVel += mAcc * dt;
		// mTransform->SetPosition({ std::round(position.x), std::round(position.y) }); // 12.53s
		mTransform->SetPosition(position); // 14.23s
	}

	void Rigidbody::LateUpdate()
	{
	}

	void Rigidbody::ResetVelocity()
	{
		mVel = Vector2::Zero;
	}

	void Rigidbody::ResetAcceleration()
	{
		mAcc = Vector2::Zero;
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

	void Rigidbody::SetGrounded(bool grounded)
	{
		mbGrounded = grounded;
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

	bool Rigidbody::IsGrounded()
	{
		return mbGrounded;
	}

} // namespace hs