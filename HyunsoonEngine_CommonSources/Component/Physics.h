#pragma once

#include "MathTypes.h"
#include "Component/Transform.h"

namespace hs
{
	class Physics : public Component
	{
	public:
		Physics();
		~Physics();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;

		void SetVelocity(Vector2& vel);
		void SetAcceleration(Vector2& acc);
		void AddVelocity(Vector2& vel);
		void AddAcceleration(Vector2& acc);

	private:
		Transform* mTransform;
		Vector2	   mVel;
		Vector2	   mAcc;
	};

} // namespace hs