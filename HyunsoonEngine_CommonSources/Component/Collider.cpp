#include "Collider.h"
#include "Component/Script.h"
#include "GameObject/GameObject.h"

namespace hs
{
	UINT Collider::CollisionID = 0;

	Collider::Collider()
		: Component(enums::eComponentType::Collider)
		, mID(CollisionID++)
		, mSize(Vector2::One)
	{
	}

	Collider::~Collider()
	{
	}

	void Collider::OnCollisionEnter(Collider* other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		script->OnCollisionEnter(other);
	}

	void Collider::OnCollisionStay(Collider* other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		script->OnCollisionStay(other);
	}

	void Collider::OnCollisionExit(Collider* other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		script->OnCollisionExit(other);
	}
} // namespace hs
