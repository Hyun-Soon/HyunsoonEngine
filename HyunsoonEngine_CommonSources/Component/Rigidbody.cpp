#include "TimeUtils.h"
#include "GameObject/GameObject.h"
#include "Rigidbody.h"
#include "Renderer.h"

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
		std::clamp<float>(mVel.x, -8, 8);
		std::clamp<float>(mVel.y, -8, 8);
		mTransform->SetPosition(position); // 14.23s
	}

	void Rigidbody::LateUpdate()
	{
	}

	void Rigidbody::Render(HDC& hdc)
	{
		// if (mbGrounded)
		//{
		//	Transform* tr = GetOwner()->GetComponent<Transform>();
		//	Vector2	   pos = tr->GetPosition();

		//	// debug
		//	if (renderer::mainCamera)
		//		pos = renderer::mainCamera->CalculatePosition(pos);

		//	HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		//	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);

		//	HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		//	HPEN oldPen = (HPEN)SelectObject(hdc, greenPen);

		//	// debug
		//	// Rigidbody* rgb = GetOwner()->GetComponent<Rigidbody>();
		//	// if (rgb && rgb->IsGrounded())
		//	//	greenPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));

		//	Rectangle(hdc, pos.x - 100, pos.y - 100, pos.x, pos.y);

		//	SelectObject(hdc, oldBrush);
		//	SelectObject(hdc, oldPen);
		//	DeleteObject(greenPen);
		//}
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