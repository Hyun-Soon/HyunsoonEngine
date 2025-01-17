#include "Projectile.h"

namespace hs
{
	Projectile::Projectile(Vector2 pos, float speed, uint32_t power, GameObject* target)
		: GameObject(pos)
		, mTarget(target)
		, mSpeed(speed)
		, mPower(power)
	{
	}

	Projectile::~Projectile()
	{
	}

	void Projectile::Update()
	{
		traceTarget();
		updatePhysics();
	}

	void Projectile::LateUpdate()
	{
	}

	void Projectile::Render(HDC& hdc)
	{
		COLORREF color = RGB(255, 255, 0);
		HBRUSH	 newBrush = CreateSolidBrush(color);
		HBRUSH	 oldBrush = (HBRUSH)SelectObject(hdc, newBrush);

		HPEN newPen = CreatePen(PS_SOLID, 2, color);
		HPEN oldPen = (HPEN)SelectObject(hdc, newPen);

		Ellipse(hdc, mPos.x, mPos.y, 50.0f + mPos.x, 50.0f + mPos.y);

		SelectObject(hdc, oldBrush);
		SelectObject(hdc, oldPen);
		DeleteObject(newBrush);
		DeleteObject(newPen);
	}

	void Projectile::traceTarget()
	{
		if (!mTarget)
			return;

		Vector2 direction = mTarget->GetPosition() - mPos;

		mVel = direction.Normalize() * mSpeed;
	}

	void Projectile::updatePhysics()
	{
		mPos += mVel * TimeUtils::GetDeltaTime();
	}
} // namespace hs