#include "GreenSnail.h"
#include "Component/Transform.h"
#include "Component/BoxCollider2D.h"
#include "Component/Rigidbody.h"
#include "Component/Animator.h"
#include "Resource/ResourceManager.h"
#include "../Component/LandMonsterScript.h"

namespace hs
{
	GreenSnail::GreenSnail()
	{
	}

	GreenSnail::~GreenSnail()
	{
	}

	void GreenSnail::Initialize()
	{
		SetName(L"GreenSnail");
		SetLayerType(enums::eLayerType::Monster);

		BoxCollider2D* boxCollider = AddComponent<BoxCollider2D>();
		Rigidbody*	   rgb = AddComponent<Rigidbody>();
		rgb->SetGravity(true);
		Animator*		   anim = AddComponent<Animator>();
		graphics::Texture* greenSnailIdle_L = ResourceManager::Find<graphics::Texture>(L"GreenSnailIdle_L");
		anim->CreateAnimation(L"GreenSnailIdle_L", greenSnailIdle_L, Vector2::Zero, { 37, 26 }, Vector2::Zero, 1, 10);
		graphics::Texture* greenSnailIdle_R = ResourceManager::Find<graphics::Texture>(L"GreenSnailIdle_R");
		anim->CreateAnimation(L"GreenSnailIdle_R", greenSnailIdle_R, Vector2::Zero, { 37, 26 }, Vector2::Zero, 1, 10);
		graphics::Texture* greenSnailMove_L = ResourceManager::Find<graphics::Texture>(L"GreenSnailMove_L");
		anim->CreateAnimation(L"GreenSnailMove_L", greenSnailMove_L, Vector2::Zero, { 37, 26 }, Vector2::Zero, 8, 0.3f);
		graphics::Texture* greenSnailMove_R = ResourceManager::Find<graphics::Texture>(L"GreenSnailMove_R");
		anim->CreateAnimation(L"GreenSnailMove_R", greenSnailMove_R, Vector2::Zero, { 37, 26 }, Vector2::Zero, 8, 0.3f);
		graphics::Texture* greenSnailAttacked_L = ResourceManager::Find<graphics::Texture>(L"GreenSnailAttacked_L");
		anim->CreateAnimation(L"GreenSnailAttacked_L", greenSnailAttacked_L, Vector2::Zero, { 43, 33 }, Vector2::Zero, 1, 10);
		graphics::Texture* greenSnailAttacked_R = ResourceManager::Find<graphics::Texture>(L"GreenSnailAttacked_R");
		anim->CreateAnimation(L"GreenSnailAttacked_R", greenSnailAttacked_R, Vector2::Zero, { 43, 33 }, Vector2::Zero, 1, 10);
		graphics::Texture* greenSnailDeath_L = ResourceManager::Find<graphics::Texture>(L"GreenSnailDeath_L");
		anim->CreateAnimation(L"GreenSnailDeath_L", greenSnailDeath_L, Vector2::Zero, { 44, 33 }, Vector2::Zero, 9, 0.1f);
		graphics::Texture* greenSnailDeath_R = ResourceManager::Find<graphics::Texture>(L"GreenSnailDeath_R");
		anim->CreateAnimation(L"GreenSnailDeath_R", greenSnailDeath_R, Vector2::Zero, { 44, 33 }, Vector2::Zero, 9, 0.1f);
		anim->PlayAnimation(L"GreenSnailIdle_L");
		LandMonsterScript* lms_greenSnail = AddComponent<LandMonsterScript>();
		lms_greenSnail->SetDeathAnimDuration(0.9f);
		lms_greenSnail->SetMinTimeToTrans(4.0f);
		lms_greenSnail->SetHp(10);
	}
} // namespace hs