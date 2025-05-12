#include "ZakumAttackEffect.h"
#include "Component/Animator.h"
#include "Resource/ResourceManager.h"

namespace hs
{
	ZakumAttackEffect::ZakumAttackEffect()
	{
	}

	ZakumAttackEffect::~ZakumAttackEffect()
	{
	}
	void ZakumAttackEffect::Initialize()
	{
		Animator* anim = AddComponent<Animator>();
		graphics::Texture* tex = ResourceManager::Find<graphics::Texture>(L"ZakumAttackEffect");
		anim->CreateAnimation(L"ZakumAttackEffect", tex, Vector2::Zero, { 177, 191 }, Vector2::Zero, 15, 0.1f);
		anim->PlayAnimation(L"ZakumAttackEffect");
		SetOffset({ -180, -90 });
		SetLifetime(1.5f);
	}
}
