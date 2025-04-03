#pragma once

#include "Component.h"
#include "MathTypes.h"

namespace hs
{
	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		virtual void Update() override;

		void RevertToPrevPos();

		void		   SetPosition(Vector2 pos) { mPosition = pos; }
		const Vector2& GetPosition() const { return mPosition; };
		const Vector2  GetCenterPosition() const;
		void		   SetScale(Vector2& scale) { mScale = scale; };
		const Vector2& GetScale() const { return mScale; };
		void		   SetRotation(float rot) { mRotation = rot; };
		const float	   GetRotation() const { return mRotation; };

	private:
		Vector2 mPosition;
		Vector2 mScale;
		float	mRotation;
		Vector2 mPrevPos;
	};
} // namespace hs