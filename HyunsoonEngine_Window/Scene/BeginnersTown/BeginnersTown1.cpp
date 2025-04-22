#include "Component/Transform.h"
#include "Component/SpriteRenderer.h"
#include "GameObject/ObjectUtils.h"
#include "Resource/ResourceManager.h"
#include "Renderer.h"
#include "Application.h"

#include "BeginnersTown1.h"
#include "../HyunsoonEngine_Window/Object/Player.h"
#include "../HyunsoonEngine_Window/Object/Monster.h"
#include "../HyunsoonEngine_Window/Component/LandMonsterScript.h"
#include "../../Object/Portal.h"
#include "../../Object/GreenSnail.h"
#include "../../Object/Background.h"

extern hs::Application app;

namespace hs
{
	BeginnersTown1::BeginnersTown1()
		: Scene(eSceneType::Hunting)
	{
	}

	BeginnersTown1::~BeginnersTown1()
	{
	}

	void BeginnersTown1::Initialize()
	{
		// CamLimit
		Scene::SetCamLimit({ 1518, 970 });

		// Background
		{
			Background* sky = object::Instantiate<Background>();
			sky->SetRatioRender(true);
			sky->SetTexture(L"bg_Sky");

			Background* terrain = object::Instantiate<Background>();
			terrain->SetTexture(L"bg_BeginnersTown1");
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
			GreenSnail* greenSnail2 = object::Instantiate<GreenSnail>({ 1200, 100 });
		}

		// Portal
		{
			Portal* portal = object::Instantiate<Portal>({ 1450, 570 });
			portal->SetName(L"BeginnersTown2");
			portal->SetDestPortalIdx(0);
		}
	}
	void BeginnersTown1::OnEnter()
	{
		Player*	   player = Player::GetInstance();
		Transform* tr = player->GetComponent<Transform>();
		Vector2	   pos = Vector2(800.0f, 300.0f);
		tr->SetPosition(pos);
	}
	void BeginnersTown1::OnExit()
	{
	}
} // namespace hs