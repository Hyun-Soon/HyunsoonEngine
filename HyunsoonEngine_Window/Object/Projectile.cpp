#include "Projectile.h"
#include "Resource/ResourceManager.h"
#include "Component/Rigidbody.h"
#include "Component/Animator.h"
#include "Component/BoxCollider2D.h"
#include "../Component/ProjectileScript.h"

namespace hs
{
	Projectile::Projectile()
		: GameObject()
		, mCaster(nullptr)
	{
	}

	Projectile::~Projectile()
	{
	}

	void Projectile::Initialize()
	{
		Rigidbody*		   rgb = AddComponent<Rigidbody>();
		Animator*		   animator = AddComponent<Animator>();
		graphics::Texture* shuriken_L = ResourceManager::Find<graphics::Texture>(L"Shuriken_L");
		animator->CreateAnimation(L"Shuriken_L", shuriken_L, Vector2::Zero, { 48, 9 }, Vector2::Zero, 2, 0.5f);
		graphics::Texture* shuriken_R = ResourceManager::Find<graphics::Texture>(L"Shuriken_R");
		animator->CreateAnimation(L"Shuriken_R", shuriken_R, Vector2::Zero, { 48, 9 }, Vector2::Zero, 2, 0.5f);
		BoxCollider2D*	  bCol = AddComponent<BoxCollider2D>();
		ProjectileScript* prjtScript = AddComponent<ProjectileScript>();
	}
} // namespace hs