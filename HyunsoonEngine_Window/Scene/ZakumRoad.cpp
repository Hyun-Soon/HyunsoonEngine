#include "Component/Transform.h"
#include "Component/SpriteRenderer.h"
#include "GameObject/ObjectUtils.h"
#include "Resource/ResourceManager.h"
#include "Renderer.h"
#include "Application.h"

#include "ZakumRoad.h"
#include "../HyunsoonEngine_Window/Object/Player.h"
#include "../HyunsoonEngine_Window/Object/Monster.h"
#include "../HyunsoonEngine_Window/Component/LandMonsterScript.h"
#include "../Object/Portal.h"
#include "../Object/GreenSnail.h"
#include "../Object/Background.h"

extern hs::Application app;

namespace hs
{
	ZakumRoad::ZakumRoad()
		: Scene(eSceneType::Hunting)
	{
	}

	ZakumRoad::~ZakumRoad()
	{
	}

	void ZakumRoad::Initialize()
	{
		Background* bg0 = object::Instantiate<Background>();
		bg0->SetTexture(L"bg_ZakumRoadBack");

		Background* bg1 = object::Instantiate<Background>();
		bg1->SetTexture(L"bg_ZakumRoad");

		// Player
		//  It will be executed in Scene::Enter() func later
		Player*	   player = Player::GetInstance();
		Transform* tr = player->GetComponent<Transform>();
		Vector2	   pos = Vector2(800.0f, 300.0f);
		tr->SetPosition(pos);
		AddGameObject(player, enums::eLayerType::Player);

		// Portal
		Portal* portal0 = object::Instantiate<Portal>({ 200, 738 });
		portal0->SetName(L"KerningCity");
		portal0->SetDestPortalIdx(0);

		Portal* portal1 = object::Instantiate<Portal>({ 1700, 2115 });
		portal1->SetName(L"AlterOfZakumEnt");
		portal1->SetDestPortalIdx(0);
	}
	void ZakumRoad::OnEnter()
	{
		Player*	   player = Player::GetInstance();
		Transform* tr = player->GetComponent<Transform>();
		Vector2	   pos = Vector2(200.0f, 100.0f);
		tr->SetPosition(pos);
	}

	void ZakumRoad::OnExit()
	{
	}
} // namespace hs