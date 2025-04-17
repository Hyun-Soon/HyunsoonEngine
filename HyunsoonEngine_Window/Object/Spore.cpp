#include "Spore.h"
#include "Component/Transform.h"
#include "Component/BoxCollider2D.h"
#include "Component/Rigidbody.h"
#include "Component/Animator.h"
#include "Resource/ResourceManager.h"
#include "../Component/LandMonsterScript.h"

namespace hs
{
	Spore::Spore()
	{
	}

	Spore::~Spore()
	{
	}

	void Spore::Initialize()
	{
		SetName(L"Spore");
		SetLayerType(enums::eLayerType::Monster);

		BoxCollider2D* boxCollider = AddComponent<BoxCollider2D>();
		Rigidbody*	   rgb = AddComponent<Rigidbody>();
		rgb->SetGravity(true);
		Animator*		   anim = AddComponent<Animator>();
		graphics::Texture* SporeIdle_L = ResourceManager::Find<graphics::Texture>(L"SporeIdle_L");
		anim->CreateAnimation(L"SporeIdle_L", SporeIdle_L, Vector2::Zero, { 36, 36 }, Vector2::Zero, 3, 0.75f);
		graphics::Texture* SporeIdle_R = ResourceManager::Find<graphics::Texture>(L"SporeIdle_R");
		anim->CreateAnimation(L"SporeIdle_R", SporeIdle_R, Vector2::Zero, { 36, 36 }, Vector2::Zero, 3, 0.75f);
		graphics::Texture* SporeMove_L = ResourceManager::Find<graphics::Texture>(L"SporeMove_L");
		anim->CreateAnimation(L"SporeMove_L", SporeMove_L, Vector2::Zero, { 41, 37 }, Vector2::Zero, 4, 0.3f);
		graphics::Texture* SporeMove_R = ResourceManager::Find<graphics::Texture>(L"SporeMove_R");
		anim->CreateAnimation(L"SporeMove_R", SporeMove_R, Vector2::Zero, { 41, 37 }, Vector2::Zero, 4, 0.3f);
		graphics::Texture* SporeAttacked_L = ResourceManager::Find<graphics::Texture>(L"SporeAttacked_L");
		anim->CreateAnimation(L"SporeAttacked_L", SporeAttacked_L, Vector2::Zero, { 36, 36 }, Vector2::Zero, 1, 10);
		graphics::Texture* SporeAttacked_R = ResourceManager::Find<graphics::Texture>(L"SporeAttacked_R");
		anim->CreateAnimation(L"SporeAttacked_R", SporeAttacked_R, Vector2::Zero, { 36, 36 }, Vector2::Zero, 1, 10);
		graphics::Texture* SporeDeath_L = ResourceManager::Find<graphics::Texture>(L"SporeDeath_L");
		anim->CreateAnimation(L"SporeDeath_L", SporeDeath_L, Vector2::Zero, { 73, 37 }, Vector2::Zero, 4, 0.2f);
		graphics::Texture* SporeDeath_R = ResourceManager::Find<graphics::Texture>(L"SporeDeath_R");
		anim->CreateAnimation(L"SporeDeath_R", SporeDeath_R, Vector2::Zero, { 73, 37 }, Vector2::Zero, 4, 0.2f);
		anim->PlayAnimation(L"SporeIdle_L");
		LandMonsterScript* lms_Spore = AddComponent<LandMonsterScript>();
		lms_Spore->SetDeathAnimDuration(0.8f);
		lms_Spore->SetMinTimeToTrans(2.5f);
		lms_Spore->SetHp(15);
	}
} // namespace hs