#include "Component/Transform.h"
#include "Component/SpriteRenderer.h"
#include "GameObject/ObjectUtils.h"
#include "Resource/ResourceManager.h"
#include "Renderer.h"
#include "Application.h"

#include "SouthFerry.h"
#include "../HyunsoonEngine_Window/Object/Player.h"
#include "../HyunsoonEngine_Window/Object/Monster.h"
#include "../HyunsoonEngine_Window/Component/LandMonsterScript.h"
#include "../Object/Portal.h"
#include "../Object/GreenSnail.h"
#include "../Object/Background.h"
#include "../Object/Npc.h"

extern hs::Application app;

namespace hs
{
	SouthFerry::SouthFerry()
		: Scene(eSceneType::Village)
	{
	}

	SouthFerry::~SouthFerry()
	{
	}

	void SouthFerry::Initialize()
	{
		// CamLimit
		Scene::SetCamLimit({ 4744, 2315 });

		Background* sky = object::Instantiate<Background>();
		sky->SetRatioRender(true);
		sky->SetTexture(L"bg_Sky");

		Background* terrain = object::Instantiate<Background>();
		terrain->SetTexture(L"bg_SouthFerry");

		// Npc
		Npc* shanks = object::Instantiate<Npc>(enums::eLayerType::Npc, { 3932, 1379 });
		shanks->SetTexture(L"Shanks");
		shanks->SetRenderName(L"Shanks");

		// Portal
		Portal* portal = object::Instantiate<Portal>({ 160, 1688 });
		portal->SetName(L"CrossRoad");
		portal->SetDestPortalIdx(1);

		Portal* portal2 = object::Instantiate<Portal>({ 4650, 1386 });
		portal2->SetName(L"KerningCity");
		portal2->SetDestPortalIdx(0);
	}
	void SouthFerry::OnEnter()
	{
		Player*	   player = Player::GetInstance();
		Transform* tr = player->GetComponent<Transform>();
		Vector2	   pos = Vector2(4000.0f, 300.0f);
		tr->SetPosition(pos);
		AddGameObject(player, enums::eLayerType::Player);
	}

	void SouthFerry::OnExit()
	{
		std::vector<GameObject*>& objs = GetLayer(enums::eLayerType::Player)->GetGameObjects();
		objs.erase(std::find(objs.begin(), objs.end(), Player::GetInstance()));
	}
} // namespace hs