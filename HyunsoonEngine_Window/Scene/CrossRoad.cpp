#include "Component/Transform.h"
#include "Component/SpriteRenderer.h"
#include "GameObject/ObjectUtils.h"
#include "Resource/ResourceManager.h"
#include "Renderer.h"
#include "Application.h"

#include "CrossRoad.h"
#include "../HyunsoonEngine_Window/Object/Player.h"
#include "../HyunsoonEngine_Window/Object/Monster.h"
#include "../HyunsoonEngine_Window/Component/LandMonsterScript.h"
#include "../Object/Portal.h"
#include "../Object/GreenSnail.h"
#include "../Object/Background.h"

namespace hs
{
	CrossRoad::CrossRoad()
		: Scene(Scene::eSceneType::Village)
	{
	}

	CrossRoad::~CrossRoad()
	{
	}

	void CrossRoad::Initialize()
	{
		Background* bg = object::Instantiate<Background>();
		bg->SetTexture(L"bg_CrossRoad");

		// Player
		//  It will be executed in Scene::Enter() func later
		Player*	   player = Player::GetInstance();
		Transform* tr = player->GetComponent<Transform>();
		Vector2	   pos = Vector2(200.0f, 300.0f);
		tr->SetPosition(pos);
		AddGameObject(player, enums::eLayerType::Player);

		// Portal
		Portal* portal0 = object::Instantiate<Portal>({ 120, 670 });
		portal0->SetName(L"BeginnersTown2");
		portal0->SetDestPortalIdx(1);

		Portal* portal1 = object::Instantiate<Portal>({ 3710, 790 });
		portal1->SetName(L"SouthFerry");
		portal1->SetDestPortalIdx(0);
	}
	void CrossRoad::OnEnter()
	{
		Player*	   player = Player::GetInstance();
		Transform* tr = player->GetComponent<Transform>();
		Vector2	   pos = Vector2(200.0f, 300.0f);
		tr->SetPosition(pos);
	}

	void CrossRoad::OnExit()
	{
	}
} // namespace hs
