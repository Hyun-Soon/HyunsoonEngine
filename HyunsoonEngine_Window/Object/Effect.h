#pragma once

#include "MathTypes.h"
#include "GameObject/GameObject.h"

namespace hs
{
	class Effect : public GameObject
	{
	public:
		Effect();
		~Effect();

		virtual void Initialize() override;
		virtual void Update() override;

		void SetOffset(Vector2 offset) { mOffset = offset; }
		void SetLifetime(float lifetime) { mLifetime = lifetime; }
		void SetDuration(float duration) { mDuration = duration; }

	private:
		Vector2 mOffset;
		float	mDuration;
		float	mLifetime;
	};


}