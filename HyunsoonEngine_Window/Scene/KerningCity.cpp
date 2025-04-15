#include "Component/Transform.h"
#include "Component/SpriteRenderer.h"
#include "GameObject/ObjectUtils.h"
#include "Resource/ResourceManager.h"
#include "Renderer.h"
#include "Application.h"

#include "KerningCity.h"
#include "../HyunsoonEngine_Window/Object/Player.h"
#include "../HyunsoonEngine_Window/Object/Monster.h"
#include "../HyunsoonEngine_Window/Component/LandMonsterScript.h"
#include "../Object/Portal.h"
#include "../Object/GreenSnail.h"
#include "../Object/Background.h"

extern hs::Application app;

namespace hs
{
	KerningCity::KerningCity()
		: Scene(eSceneType::Village)
	{
	}

	KerningCity::~KerningCity()
	{
	}

	void KerningCity::Initialize()
	{
		// Background* bg0 = object::Instantiate<Background>();
		// bg0->SetTexture(L"bg_KerningCityBack");

		Background* bg1 = object::Instantiate<Background>();
		bg1->SetTexture(L"bg_KerningCity");

		// Player
		//  It will be executed in Scene::Enter() func later
		Player*	   player = Player::GetInstance();
		Transform* tr = player->GetComponent<Transform>();
		Vector2	   pos = Vector2(800.0f, 300.0f);
		tr->SetPosition(pos);
		AddGameObject(player, enums::eLayerType::Player);

		// Portal
		Portal* portal = object::Instantiate<Portal>({ 1708, 1828 });
		portal->SetName(L"ZakumRoad");
		portal->SetDestPortalIdx(0);
	}
	void KerningCity::OnEnter()
	{
		Player*	   player = Player::GetInstance();
		Transform* tr = player->GetComponent<Transform>();
		Vector2	   pos = Vector2(200.0f, 600.0f);
		tr->SetPosition(pos);
	}

	void KerningCity::OnExit()
	{
	}
} // namespace hs