#include "Effect.h"
#include "TimeUtils.h"
#include "GameObject/ObjectUtils.h"
#include "Component/Animator.h"

namespace hs
{
	Effect::Effect()
		: mOffset(Vector2::Zero)
		, mDuration(0.0f)
		, mLifetime(0.0f)
	{
	}

	Effect::~Effect()
	{
	}

	void Effect::Initialize()
	{
		AddComponent<Animator>();
	}

	void Effect::Update()
	{
		mDuration += TimeUtils::GetDeltaTime();
		if (mLifetime < mDuration)
			object::Destroy(this);

		Transform* tr = GetComponent<Transform>();
		Transform* parentTr = GetParent()->GetComponent<Transform>();
		tr->SetPosition(parentTr->GetPosition() + mOffset);

		GameObject::Update();
	}


}