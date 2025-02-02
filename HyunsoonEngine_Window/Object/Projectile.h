#pragma once

#include "GameObject/GameObject.h"

namespace hs
{
	class Projectile : public GameObject
	{
	public:
		Projectile(Vector2 pos, float speed, uint32_t power, GameObject* target);
		~Projectile();

		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC& hdc) override;

	private:
		void traceTarget();
		void updatePhysics();

		GameObject* mTarget;
		float		mSpeed;
		Vector2		mVel;

		uint32_t mPower;
	};

} // namespace hs