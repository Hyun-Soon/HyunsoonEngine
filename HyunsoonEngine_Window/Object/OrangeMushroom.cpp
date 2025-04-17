#include "OrangeMushroom.h"
#include "Component/Transform.h"
#include "Component/BoxCollider2D.h"
#include "Component/Rigidbody.h"
#include "Component/Animator.h"
#include "Resource/ResourceManager.h"
#include "../Component/LandMonsterScript.h"

namespace hs
{
	OrangeMushroom::OrangeMushroom()
	{
	}

	OrangeMushroom::~OrangeMushroom()
	{
	}

	void OrangeMushroom::Initialize()
	{
		SetName(L"OrangeMushroom");
		SetLayerType(enums::eLayerType::Monster);
		SetSpeed(30.0f);

		BoxCollider2D* boxCollider = AddComponent<BoxCollider2D>();
		Rigidbody*	   rgb = AddComponent<Rigidbody>();
		rgb->SetGravity(true);
		Animator*		   anim = AddComponent<Animator>();
		graphics::Texture* OrangeMushroomIdle_L = ResourceManager::Find<graphics::Texture>(L"OrangeMushroomIdle_L");
		anim->CreateAnimation(L"OrangeMushroomIdle_L", OrangeMushroomIdle_L, Vector2::Zero, { 70, 62 }, Vector2::Zero, 2, 0.5f);
		graphics::Texture* OrangeMushroomIdle_R = ResourceManager::Find<graphics::Texture>(L"OrangeMushroomIdle_R");
		anim->CreateAnimation(L"OrangeMushroomIdle_R", OrangeMushroomIdle_R, Vector2::Zero, { 70, 62 }, Vector2::Zero, 2, 0.5f);
		graphics::Texture* OrangeMushroomMove_L = ResourceManager::Find<graphics::Texture>(L"OrangeMushroomMove_L");
		anim->CreateAnimation(L"OrangeMushroomMove_L", OrangeMushroomMove_L, Vector2::Zero, { 68, 65 }, Vector2::Zero, 3, 0.33f);
		graphics::Texture* OrangeMushroomMove_R = ResourceManager::Find<graphics::Texture>(L"OrangeMushroomMove_R");
		anim->CreateAnimation(L"OrangeMushroomMove_R", OrangeMushroomMove_R, Vector2::Zero, { 68, 65 }, Vector2::Zero, 3, 0.33f);
		graphics::Texture* OrangeMushroomAttacked_L = ResourceManager::Find<graphics::Texture>(L"OrangeMushroomAttacked_L");
		anim->CreateAnimation(L"OrangeMushroomAttacked_L", OrangeMushroomAttacked_L, Vector2::Zero, { 68, 65 }, Vector2::Zero, 1, 10);
		graphics::Texture* OrangeMushroomAttacked_R = ResourceManager::Find<graphics::Texture>(L"OrangeMushroomAttacked_R");
		anim->CreateAnimation(L"OrangeMushroomAttacked_R", OrangeMushroomAttacked_R, Vector2::Zero, { 68, 65 }, Vector2::Zero, 1, 10);
		graphics::Texture* OrangeMushroomDeath_L = ResourceManager::Find<graphics::Texture>(L"OrangeMushroomDeath_L");
		anim->CreateAnimation(L"OrangeMushroomDeath_L", OrangeMushroomDeath_L, Vector2::Zero, { 68, 65 }, Vector2::Zero, 3, 0.33f);
		graphics::Texture* OrangeMushroomDeath_R = ResourceManager::Find<graphics::Texture>(L"OrangeMushroomDeath_R");
		anim->CreateAnimation(L"OrangeMushroomDeath_R", OrangeMushroomDeath_R, Vector2::Zero, { 68, 65 }, Vector2::Zero, 3, 0.33f);
		anim->PlayAnimation(L"OrangeMushroomIdle_R");
		LandMonsterScript* lms_OrangeMushroom = AddComponent<LandMonsterScript>();
		lms_OrangeMushroom->SetDeathAnimDuration(0.99f);
		lms_OrangeMushroom->SetMinTimeToTrans(2.0f);
		lms_OrangeMushroom->SetHp(17);
	}
} // namespace hs