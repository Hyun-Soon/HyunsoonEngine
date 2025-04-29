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
#include "../Object/Zakum/Zakum.h"
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
		//JrBalrog* jrBalrog = object::Instantiate<JrBalrog>({ 800, 500 });
		Zakum* zakum = object::Instantiate<Zakum>({ 800, 657 });

		// Portal
		Portal* portal = object::Instantiate<Portal>({ 200, 657 });
		portal->SetName(L"AlterOfZakumEnt");
		portal->SetDestPortalIdx(1);

		// test
		//GameObject* obj = object::Instantiate<GameObject>(enums::eLayerType::Monster, { 600, 500 });
		// SpriteRenderer*	   spr = obj->AddComponent<SpriteRenderer>();
		// graphics::Texture* testtex = ResourceManager::Find<graphics::Texture>(L"test");
		// spr->SetTexture(testtex);

		/*Animator*		   anim = obj->AddComponent<Animator>();
		graphics::Texture* tex = ResourceManager::Find<graphics::Texture>(L"SkillLock");
		anim->CreateAnimation(L"SkillLock", tex, Vector2::Zero, { 73, 47 }, Vector2::Zero, 10, 0.2f);
		anim->PlayAnimation(L"SkillLock");*/

		/*Animator* anim = obj->AddComponent<Animator>();
		graphics::Texture* tex = ResourceManager::Find<graphics::Texture>(L"AccuracyDrop");
		anim->CreateAnimation(L"AccuracyDrop", tex, Vector2::Zero, { 48, 52 }, Vector2::Zero, 7, 0.2f);
		anim->PlayAnimation(L"AccuracyDrop");*/

		/*Animator* anim = obj->AddComponent<Animator>();
		graphics::Texture* tex = ResourceManager::Find<graphics::Texture>(L"CannotJump");
		anim->CreateAnimation(L"CannotJump", tex, Vector2::Zero, { 43, 41 }, Vector2::Zero, 6, 0.2f);
		anim->PlayAnimation(L"CannotJump");*/
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