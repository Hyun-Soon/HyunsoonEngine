#include "Zombie.h"
#include "Component/Transform.h"
#include "Component/BoxCollider2D.h"
#include "Component/Rigidbody.h"
#include "Component/Animator.h"
#include "Resource/ResourceManager.h"
#include "../Component/LandMonsterScript.h"

namespace hs
{
	Zombie::Zombie()
	{
	}

	Zombie::~Zombie()
	{
	}

	void Zombie::Initialize()
	{
		SetName(L"Zombie");
		SetLayerType(enums::eLayerType::Monster);

		BoxCollider2D* boxCollider = AddComponent<BoxCollider2D>();
		Rigidbody*	   rgb = AddComponent<Rigidbody>();
		rgb->SetGravity(true);
		Animator*		   anim = AddComponent<Animator>();
		graphics::Texture* ZombieIdle_L = ResourceManager::Find<graphics::Texture>(L"ZombieIdle_L");
		anim->CreateAnimation(L"ZombieIdle_L", ZombieIdle_L, Vector2::Zero, { 81, 98 }, Vector2::Zero, 3, 0.75f);
		graphics::Texture* ZombieIdle_R = ResourceManager::Find<graphics::Texture>(L"ZombieIdle_R");
		anim->CreateAnimation(L"ZombieIdle_R", ZombieIdle_R, Vector2::Zero, { 81, 98 }, Vector2::Zero, 3, 0.75f);
		graphics::Texture* ZombieMove_L = ResourceManager::Find<graphics::Texture>(L"ZombieMove_L");
		anim->CreateAnimation(L"ZombieMove_L", ZombieMove_L, Vector2::Zero, { 81, 98 }, Vector2::Zero, 3, 0.3f);
		graphics::Texture* ZombieMove_R = ResourceManager::Find<graphics::Texture>(L"ZombieMove_R");
		anim->CreateAnimation(L"ZombieMove_R", ZombieMove_R, Vector2::Zero, { 81, 98 }, Vector2::Zero, 3, 0.3f);
		graphics::Texture* ZombieAttacked_L = ResourceManager::Find<graphics::Texture>(L"ZombieAttacked_L");
		anim->CreateAnimation(L"ZombieAttacked_L", ZombieAttacked_L, Vector2::Zero, { 81, 98 }, Vector2::Zero, 1, 10);
		graphics::Texture* ZombieAttacked_R = ResourceManager::Find<graphics::Texture>(L"ZombieAttacked_R");
		anim->CreateAnimation(L"ZombieAttacked_R", ZombieAttacked_R, Vector2::Zero, { 81, 98 }, Vector2::Zero, 1, 10);
		graphics::Texture* ZombieDeath_L = ResourceManager::Find<graphics::Texture>(L"ZombieDeath_L");
		anim->CreateAnimation(L"ZombieDeath_L", ZombieDeath_L, Vector2::Zero, { 81, 98 }, Vector2::Zero, 10, 0.1f);
		graphics::Texture* ZombieDeath_R = ResourceManager::Find<graphics::Texture>(L"ZombieDeath_R");
		anim->CreateAnimation(L"ZombieDeath_R", ZombieDeath_R, Vector2::Zero, { 81, 98 }, Vector2::Zero, 10, 0.1f);
		anim->PlayAnimation(L"ZombieIdle_L");
		LandMonsterScript* lms_Zombie = AddComponent<LandMonsterScript>();
		lms_Zombie->SetDeathAnimDuration(1.0f);
		lms_Zombie->SetMinTimeToTrans(2.5f);
		lms_Zombie->SetHp(20);
	}
} // namespace hs