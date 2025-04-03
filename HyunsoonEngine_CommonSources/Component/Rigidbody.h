#pragma once

#include "MathTypes.h"
#include "Component/Transform.h"

namespace hs
{
	class Rigidbody : public Component
	{
	public:
		Rigidbody();
		~Rigidbody();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;

		void	ResetVelocity();
		void	ResetAcceleration();
		void	SetVelocity(Vector2 vel);
		Vector2 GetVelocity() const { return mVel; }
		void	SetAcceleration(Vector2 acc);
		void	SetGravity(bool enable);
		void	SetKinematic(bool enable);
		void	SetGrounded(bool grounded);
		void	AddVelocity(Vector2 vel);
		void	AddAcceleration(Vector2 acc);
		void	AddForce(Vector2 force);

		bool IsGrounded();

	private:
		Transform* mTransform;
		float	   mMass;
		Vector2	   mVel;
		Vector2	   mAcc;
		bool	   mbUseGravity;
		bool	   mbIsKinematic;
		bool	   mbGrounded;
	};

} // namespace hs