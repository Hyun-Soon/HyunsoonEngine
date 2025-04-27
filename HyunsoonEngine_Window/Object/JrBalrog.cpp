#include "JrBalrog.h"
#include "Component/Transform.h"
#include "Component/BoxCollider2D.h"
#include "Component/Rigidbody.h"
#include "Component/Animator.h"
#include "Resource/ResourceManager.h"
#include "../Component/JrBalrogScript.h"

namespace hs
{
	JrBalrog::JrBalrog()
	{
	}

	JrBalrog::~JrBalrog()
	{
	}

	void JrBalrog::Initialize()
	{
		SetName(L"JrBalrog");
		SetLayerType(enums::eLayerType::Monster);

		BoxCollider2D* boxCollider = AddComponent<BoxCollider2D>();
		Rigidbody*	   rgb = AddComponent<Rigidbody>();
		rgb->SetGravity(true);
		Animator*		   anim = AddComponent<Animator>();
		graphics::Texture* jrBalrogIdle_L = ResourceManager::Find<graphics::Texture>(L"JrBalrogIdle_L");
		anim->CreateAnimation(L"JrBalrogIdle_L", jrBalrogIdle_L, Vector2::Zero, { 160, 157 }, Vector2::Zero, 1, 10);
		graphics::Texture* jrBalrogIdle_R = ResourceManager::Find<graphics::Texture>(L"JrBalrogIdle_R");
		anim->CreateAnimation(L"JrBalrogIdle_R", jrBalrogIdle_R, Vector2::Zero, { 160, 157 }, Vector2::Zero, 1, 10);
		graphics::Texture* jrBalrogMove_L = ResourceManager::Find<graphics::Texture>(L"JrBalrogMove_L");
		anim->CreateAnimation(L"JrBalrogMove_L", jrBalrogMove_L, Vector2::Zero, { 172, 170 }, Vector2::Zero, 5, 0.8f);
		graphics::Texture* jrBalrogMove_R = ResourceManager::Find<graphics::Texture>(L"JrBalrogMove_R");
		anim->CreateAnimation(L"JrBalrogMove_R", jrBalrogMove_R, Vector2::Zero, { 172, 170 }, Vector2::Zero, 5, 0.8f);
		graphics::Texture* jrBalrogAttacked_L = ResourceManager::Find<graphics::Texture>(L"JrBalrogAttacked_L");
		anim->CreateAnimation(L"JrBalrogAttacked_L", jrBalrogAttacked_L, Vector2::Zero, { 172, 159 }, Vector2::Zero, 1, 10);
		graphics::Texture* jrBalrogAttacked_R = ResourceManager::Find<graphics::Texture>(L"JrBalrogAttacked_R");
		anim->CreateAnimation(L"JrBalrogAttacked_R", jrBalrogAttacked_R, Vector2::Zero, { 172, 159 }, Vector2::Zero, 1, 10);
		graphics::Texture* jrBalrogAttack1_L = ResourceManager::Find<graphics::Texture>(L"JrBalrogAttack1_L");
		anim->CreateAnimation(L"JrBalrogAttack1_L", jrBalrogAttack1_L, Vector2::Zero, { 202, 187 }, Vector2::Zero, 3, 0.3);
		graphics::Texture* jrBalrogAttack1_R = ResourceManager::Find<graphics::Texture>(L"JrBalrogAttack1_R");
		anim->CreateAnimation(L"JrBalrogAttack1_R", jrBalrogAttack1_R, Vector2::Zero, { 202, 187 }, Vector2::Zero, 3, 0.3);
		graphics::Texture* jrBalrogAttack2_L = ResourceManager::Find<graphics::Texture>(L"JrBalrogAttack2_L");
		anim->CreateAnimation(L"JrBalrogAttack2_L", jrBalrogAttack2_L, Vector2::Zero, { 202, 171 }, Vector2::Zero, 3, 0.3);
		graphics::Texture* jrBalrogAttack2_R = ResourceManager::Find<graphics::Texture>(L"JrBalrogAttack2_R");
		anim->CreateAnimation(L"JrBalrogAttack2_R", jrBalrogAttack2_R, Vector2::Zero, { 202, 171 }, Vector2::Zero, 3, 0.3);
		graphics::Texture* jrBalrogDeath_L = ResourceManager::Find<graphics::Texture>(L"JrBalrogDeath_L");
		anim->CreateAnimation(L"JrBalrogDeath_L", jrBalrogDeath_L, Vector2::Zero, { 239, 163 }, Vector2::Zero, 3, 0.3f);
		graphics::Texture* jrBalrogDeath_R = ResourceManager::Find<graphics::Texture>(L"JrBalrogDeath_R");
		anim->CreateAnimation(L"JrBalrogDeath_R", jrBalrogDeath_R, Vector2::Zero, { 239, 163 }, Vector2::Zero, 3, 0.3f);
		anim->PlayAnimation(L"JrBalrogIdle_L");
		JrBalrogScript* lms_jrBalrog = AddComponent<JrBalrogScript>();
		lms_jrBalrog->SetDeathAnimDuration(0.9f);
		lms_jrBalrog->SetMinTimeToTrans(2.0f);
		lms_jrBalrog->SetHp(10);
	}
} // namespace hs