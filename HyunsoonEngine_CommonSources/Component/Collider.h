#pragma once

#include "MathTypes.h"
#include "Component.h"

namespace hs
{
	class Collider : public Component
	{
	public:
		Collider();
		~Collider();

		virtual void Initialize() = 0;
		virtual void Update() = 0;
		virtual void LateUpdate() = 0;
		virtual void Render(HDC& hdc) = 0;

		virtual void OnCollisionEnter(Collider* other);
		virtual void OnCollisionStay(Collider* other);
		virtual void OnCollisionExit(Collider* other);

		Vector2 GetOffset() const { return mOffset; }
		void	SetOffset(Vector2 offset) { mOffset = offset; }
		UINT32	GetID() const { return mID; }
		Vector2 GetSize() const { return mSize; }
		void	SetSize(Vector2 size) { mSize = size; }

	private:
		static UINT CollisionID;

		UINT32	mID;
		Vector2 mOffset;
		Vector2 mSize;
	};
} // namespace hs
