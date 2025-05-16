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
		// CamLimit
		Scene::SetCamLimit({ 5200, 2163 });

		Background* sky = object::Instantiate<Background>();
		sky->SetRatioRender(true);
		sky->SetTexture(L"bg_KerningCityBack");

		Background* bg1 = object::Instantiate<Background>();
		bg1->SetTexture(L"bg_KerningCity");

		// Player
		//  It will be executed in Scene::Enter() func later
		/*Player*	   player = Player::GetInstance();
		Transform* tr = player->GetComponent<Transform>();
		Vector2	   pos = Vector2(800.0f, 300.0f);
		tr->SetPosition(pos);
		AddGameObject(player, enums::eLayerType::Player);*/

		// Portal
		Portal* portal = object::Instantiate<Portal>({ 250, 1490 });
		portal->SetName(L"SouthFerry");
		portal->SetDestPortalIdx(1);

		Portal* portal1 = object::Instantiate<Portal>({ 1708, 1828 });
		portal1->SetName(L"ZakumRoad");
		portal1->SetDestPortalIdx(0);
	}
	void KerningCity::OnEnter()
	{
		Player*	   player = Player::GetInstance();
		Transform* tr = player->GetComponent<Transform>();
		Vector2	   pos = Vector2(200.0f, 1400.0f);
		tr->SetPosition(pos);
		AddGameObject(player, enums::eLayerType::Player);
	}

	void KerningCity::OnExit()
	{
		std::vector<GameObject*>& objs = GetLayer(enums::eLayerType::Player)->GetGameObjects();
		objs.erase(std::find(objs.begin(), objs.end(), Player::GetInstance()));
	}
} // namespace hs