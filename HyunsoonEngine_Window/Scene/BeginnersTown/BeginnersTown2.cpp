#include "Component/Transform.h"
#include "Component/SpriteRenderer.h"
#include "GameObject/ObjectUtils.h"
#include "Resource/ResourceManager.h"
#include "Renderer.h"
#include "Application.h"

#include "BeginnersTown2.h"
#include "../HyunsoonEngine_Window/Object/Player.h"
#include "../HyunsoonEngine_Window/Object/Monster.h"
#include "../HyunsoonEngine_Window/Component/LandMonsterScript.h"
#include "../../Object/Portal.h"
#include "../../Object/GreenSnail.h"
#include "../../Object/Background.h"

extern hs::Application app;

namespace hs
{
	BeginnersTown2::BeginnersTown2()
		: Scene(eSceneType::Hunting)
	{
	}

	BeginnersTown2::~BeginnersTown2()
	{
	}

	void BeginnersTown2::Initialize()
	{
		// Background
		{
			Background* bg = object::Instantiate<Background>();
			bg->SetTexture(L"bg_BeginnersTown2");
		}

		// Player
		{
			//  It will be executed in Scene::Enter() func later
			Player*	   player = Player::GetInstance();
			Transform* tr = player->GetComponent<Transform>();
			Vector2	   pos = Vector2(800.0f, 300.0f);
			tr->SetPosition(pos);
			AddGameObject(player, enums::eLayerType::Player);
		}

		// Monster
		{
			GreenSnail* greenSnail1 = object::Instantiate<GreenSnail>({ 300, 500 });
		}

		// Portal
		{
			Portal* portal0 = object::Instantiate<Portal>({ 130, 465 });
			portal0->SetName(L"BeginnersTown1");
			portal0->SetDestPortalIdx(0);

			Portal* portal1 = object::Instantiate<Portal>({ 1100, 400 });
			portal1->SetName(L"SouthFerry");
			portal1->SetDestPortalIdx(0);
		}
	}
	void BeginnersTown2::OnEnter()
	{
		Player*	   player = Player::GetInstance();
		Transform* tr = player->GetComponent<Transform>();
		Vector2	   pos = Vector2(800.0f, 300.0f);
		tr->SetPosition(pos);
	}

	void BeginnersTown2::OnExit()
	{
	}
} // namespace hs