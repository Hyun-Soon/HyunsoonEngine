#include "Component/Transform.h"
#include "Component/SpriteRenderer.h"
#include "GameObject/ObjectUtils.h"
#include "Resource/ResourceManager.h"
#include "Resource/Texture.h"
#include "Renderer.h"
#include "Application.h"

#include "AlterOfZakum.h"
#include "../HyunsoonEngine_Window/Object/Player.h"
#include "../HyunsoonEngine_Window/Object/Monster.h"
#include "../HyunsoonEngine_Window/Component/LandMonsterScript.h"
#include "../Object/Portal.h"
#include "../Object/JrBalrog.h"
#include "../Object/Background.h"

extern hs::Application app;

namespace hs
{
	AlterOfZakum::AlterOfZakum()
		: Scene(eSceneType::Hunting)
	{
	}

	AlterOfZakum::~AlterOfZakum()
	{
	}

	void AlterOfZakum::Initialize()
	{
		// CamLimit
		Scene::SetCamLimit({ 1214, 950 });

		Background* larva = object::Instantiate<Background>();
		larva->SetRatioRender(true);
		larva->SetTexture(L"bg_Alter");

		Background* bg = object::Instantiate<Background>();
		bg->SetTexture(L"bg_AlterOfZakum");

		// Player
		Player* player = Player::GetInstance();
		AddGameObject(player, enums::eLayerType::Player);

		// Monster
		JrBalrog* jrBalrog = object::Instantiate<JrBalrog>({ 800, 500 });

		// Portal
		Portal* portal = object::Instantiate<Portal>({ 200, 657 });
		portal->SetName(L"AlterOfZakumEnt");
		portal->SetDestPortalIdx(1);

		// test
		GameObject* obj = object::Instantiate<GameObject>(enums::eLayerType::Monster, { 600, 500 });
		// SpriteRenderer*	   spr = obj->AddComponent<SpriteRenderer>();
		// graphics::Texture* testtex = ResourceManager::Find<graphics::Texture>(L"test");
		// spr->SetTexture(testtex);
		Animator*		   anim = obj->AddComponent<Animator>();
		graphics::Texture* tex = ResourceManager::Find<graphics::Texture>(L"ZakumSpawn0");
		anim->CreateAnimation(L"ZakumSpawn0", tex, Vector2::Zero, { 795, 513 }, Vector2::Zero, 21, 0.3f);
		anim->PlayAnimation(L"ZakumSpawn0");
	}
	void AlterOfZakum::OnEnter()
	{
		Player*	   player = Player::GetInstance();
		Transform* tr = player->GetComponent<Transform>();
		Vector2	   pos = Vector2(200.0f, 300.0f);
		tr->SetPosition(pos);
	}

	void AlterOfZakum::OnExit()
	{
	}
} // namespace hs