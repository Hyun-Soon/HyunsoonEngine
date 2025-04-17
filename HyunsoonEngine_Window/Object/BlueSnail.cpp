#include "BlueSnail.h"
#include "Component/Transform.h"
#include "Component/BoxCollider2D.h"
#include "Component/Rigidbody.h"
#include "Component/Animator.h"
#include "Resource/ResourceManager.h"
#include "../Component/LandMonsterScript.h"

namespace hs
{
	BlueSnail::BlueSnail()
	{
	}

	BlueSnail::~BlueSnail()
	{
	}

	void BlueSnail::Initialize()
	{
		SetName(L"BlueSnail");
		SetLayerType(enums::eLayerType::Monster);

		BoxCollider2D* boxCollider = AddComponent<BoxCollider2D>();
		Rigidbody*	   rgb = AddComponent<Rigidbody>();
		rgb->SetGravity(true);
		Animator*		   anim = AddComponent<Animator>();
		graphics::Texture* blueSnailIdle_L = ResourceManager::Find<graphics::Texture>(L"BlueSnailIdle_L");
		anim->CreateAnimation(L"BlueSnailIdle_L", blueSnailIdle_L, Vector2::Zero, { 35, 34 }, Vector2::Zero, 1, 10);
		graphics::Texture* blueSnailIdle_R = ResourceManager::Find<graphics::Texture>(L"BlueSnailIdle_R");
		anim->CreateAnimation(L"BlueSnailIdle_R", blueSnailIdle_R, Vector2::Zero, { 35, 34 }, Vector2::Zero, 1, 10);
		graphics::Texture* blueSnailMove_L = ResourceManager::Find<graphics::Texture>(L"BlueSnailMove_L");
		anim->CreateAnimation(L"BlueSnailMove_L", blueSnailMove_L, Vector2::Zero, { 44, 34 }, Vector2::Zero, 4, 0.3f);
		graphics::Texture* blueSnailMove_R = ResourceManager::Find<graphics::Texture>(L"BlueSnailMove_R");
		anim->CreateAnimation(L"BlueSnailMove_R", blueSnailMove_R, Vector2::Zero, { 44, 34 }, Vector2::Zero, 4, 0.3f);
		graphics::Texture* blueSnailAttacked_L = ResourceManager::Find<graphics::Texture>(L"BlueSnailAttacked_L");
		anim->CreateAnimation(L"BlueSnailAttacked_L", blueSnailAttacked_L, Vector2::Zero, { 41, 39 }, Vector2::Zero, 1, 10);
		graphics::Texture* blueSnailAttacked_R = ResourceManager::Find<graphics::Texture>(L"BlueSnailAttacked_R");
		anim->CreateAnimation(L"BlueSnailAttacked_R", blueSnailAttacked_R, Vector2::Zero, { 41, 39 }, Vector2::Zero, 1, 10);
		graphics::Texture* blueSnailDeath_L = ResourceManager::Find<graphics::Texture>(L"BlueSnailDeath_L");
		anim->CreateAnimation(L"BlueSnailDeath_L", blueSnailDeath_L, Vector2::Zero, { 56, 32 }, Vector2::Zero, 3, 0.2f);
		graphics::Texture* blueSnailDeath_R = ResourceManager::Find<graphics::Texture>(L"BlueSnailDeath_R");
		anim->CreateAnimation(L"BlueSnailDeath_R", blueSnailDeath_R, Vector2::Zero, { 56, 32 }, Vector2::Zero, 3, 0.2f);
		anim->PlayAnimation(L"BlueSnailIdle_L");
		LandMonsterScript* lms_blueSnail = AddComponent<LandMonsterScript>();
		lms_blueSnail->SetDeathAnimDuration(0.6f);
		lms_blueSnail->SetMinTimeToTrans(3.0f);
		lms_blueSnail->SetHp(15);
	}
} // namespace hs