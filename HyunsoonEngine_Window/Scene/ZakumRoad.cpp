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
		/*Portal* portal = object::Instantiate<Portal>({ 160, 1688 });
		portal->SetName(L"CrossRoad");
		portal->SetDestPortalIdx(1);*/
	}
	void ZakumRoad::OnEnter()
	{
		Player*	   player = Player::GetInstance();
		Transform* tr = player->GetComponent<Transform>();
		Vector2	   pos = Vector2(800.0f, 300.0f);
		tr->SetPosition(pos);
	}

	void ZakumRoad::OnExit()
	{
	}
} // namespace hs