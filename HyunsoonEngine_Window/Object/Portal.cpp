#include "Portal.h"
#include "Component/Transform.h"
#include "Component/Animator.h"
#include "Resource/ResourceManager.h"
#include "CollisionManager.h"

namespace hs
{
	Portal::Portal()
		: mDestPortalIdx(0)
	{
	}

	Portal::~Portal()
	{
	}

	void Portal::Initialize()
	{
		SetLayerType(enums::eLayerType::Particle);

		Transform*		   portalTr = GetComponent<Transform>();
		Animator*		   portalAm = AddComponent<Animator>();
		graphics::Texture* portalTexture = ResourceManager::Find<graphics::Texture>(L"Portal");
		portalAm->CreateAnimation(L"Portal", portalTexture, Vector2::Zero, { 90, 160 }, Vector2::Zero, 8, 0.15f);
		portalAm->PlayAnimation(L"Portal");
		BoxCollider2D* portalCol = AddComponent<BoxCollider2D>();
	}

} // namespace hs