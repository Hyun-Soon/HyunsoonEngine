#pragma once

#include "../Enums/Enums.h"
#include "../MathTypes.h"
#include "Component.h"

namespace hs
{
	using namespace enums;

	class Collider : public Component
	{
	public:
		Collider(eColliderType type);
		~Collider();

		virtual void Initialize();
		virtual void Update() = 0;
		virtual void LateUpdate() = 0;
		virtual void Render(HDC& hdc) = 0;

		virtual void OnCollisionEnter(Collider* other);
		virtual void OnCollisionStay(Collider* other);
		virtual void OnCollisionExit(Collider* other);

		Vector2		  GetOffset() const { return mOffset; }
		void		  SetOffset(Vector2 offset) { mOffset = offset; }
		UINT32		  GetID() const { return mID; }
		Vector2		  GetSize() const { return mSize; }
		void		  SetSize(Vector2 size) { mSize = size; }
		eColliderType GetColliderType() const { return mType; }
		eLayerType	  GetLayerType() const { return mOwnerLayerType; }

	private:
		static UINT CollisionID;

		eColliderType mType;
		eLayerType	  mOwnerLayerType;
		UINT32		  mID;
		Vector2		  mOffset;
		Vector2		  mSize;
	};
} // namespace hs
