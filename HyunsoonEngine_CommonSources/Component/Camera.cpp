#include "Camera.h"
#include "GameObject/GameObject.h"
#include "Transform.h"
#include "Application.h"
#include "Scene/SceneManager.h"

extern hs::Application app;

namespace hs
{
	Camera::Camera()
		: Component(enums::eComponentType::Camera)
		, mDistance(Vector2::Zero)
		, mResolution(Vector2::Zero)
		, mLookPosition(Vector2::Zero)
		, mTarget(nullptr)
		, mRatio(Vector2::Zero)
	{
	}

	Camera::~Camera()
	{
	}

	void Camera::Initialize()
	{
		mResolution = app.GetResolution();
	}

	void Camera::Update()
	{
		if (mTarget)
		{
			Transform* tr = mTarget->GetComponent<Transform>();
			mLookPosition = tr->GetPosition();
		}
		else
		{
			Transform* cameraTr = GetOwner()->GetComponent<Transform>();
			mLookPosition = cameraTr->GetPosition();
		}

		Vector2 camLimit = SceneManager::GetActiveScene()->GetCamLimit();
		Vector2 halfRes = mResolution / 2.0f;
		float	clampedX = std::clamp<float>(mLookPosition.x, halfRes.x, camLimit.x - halfRes.x);
		float	clampedY = std::clamp<float>(mLookPosition.y, halfRes.y, camLimit.y - halfRes.y);

		mDistance = Vector2(clampedX, clampedY) - (mResolution / 2.0f);
		mRatio = mDistance / mResolution * 0.1f;
	}

	Vector2 Camera::CalculateRatioPosition(Vector2 pos, Vector2 res)
	{
		return pos - res * mRatio;
	}
} // namespace hs
