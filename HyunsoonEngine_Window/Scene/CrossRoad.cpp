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
#include "../Object/BlueSnail.h"
#include "../Object/Spore.h"
#include "../Object/OrangeMushroom.h"
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
		// CamLimit
		Scene::SetCamLimit({ 3858, 1195 });

		Background* sky = object::Instantiate<Background>();
		sky->SetRatioRender(true);
		sky->SetTexture(L"bg_Sky");

		Background* terrain = object::Instantiate<Background>();
		terrain->SetTexture(L"bg_CrossRoad");

		// Player
		//  It will be executed in Scene::Enter() func later
		Player*	   player = Player::GetInstance();
		Transform* tr = player->GetComponent<Transform>();
		Vector2	   pos = Vector2(200.0f, 300.0f);
		tr->SetPosition(pos);
		AddGameObject(player, enums::eLayerType::Player);

		// Monster
		GreenSnail* greenSnail0 = object::Instantiate<GreenSnail>({ 2300, 1500 });

		BlueSnail* blueSnail0 = object::Instantiate<BlueSnail>({ 700, 1500 });
		BlueSnail* blueSnail1 = object::Instantiate<BlueSnail>({ 2000, 1500 });

		Spore* spore1 = object::Instantiate<Spore>({ 500, 1500 });
		Spore* spore2 = object::Instantiate<Spore>({ 1200, 1500 });

		OrangeMushroom* orangeMushroom0 = object::Instantiate<OrangeMushroom>({ 600, 1500 });
		OrangeMushroom* orangeMushroom1 = object::Instantiate<OrangeMushroom>({ 2300, 1500 });

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
