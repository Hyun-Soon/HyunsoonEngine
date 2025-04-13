#include "Collider.h"
#include "Component/Script.h"
#include "GameObject/GameObject.h"

namespace hs
{
	UINT Collider::CollisionID = 0;

	Collider::Collider(enums::eColliderType type)
		: Component(enums::eComponentType::Collider)
		, mOwnerLayerType(enums::eLayerType::None)
		, mType(type)
		, mID(CollisionID++)
		, mSize(Vector2::One)
	{
	}

	Collider::~Collider()
	{
	}

	void Collider::Initialize()
	{
		mOwnerLayerType = GetOwner()->GetLayerType();
	}

	void Collider::OnCollisionEnter(Collider* other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		if (script)
			script->OnCollisionEnter(other);
	}

	void Collider::OnCollisionStay(Collider* other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		if (script)
			script->OnCollisionStay(other);
	}

	void Collider::OnCollisionExit(Collider* other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		if (script)
			script->OnCollisionExit(other);
	}
} // namespace hs
