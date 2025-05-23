#include "Component/Transform.h"
#include "Component/SpriteRenderer.h"
#include "GameObject/ObjectUtils.h"
#include "Resource/ResourceManager.h"
#include "Resource/Texture.h"
#include "Renderer.h"
#include "Application.h"

#include "AlterOfZakumEnt.h"
#include "../HyunsoonEngine_Window/Object/Player.h"
#include "../HyunsoonEngine_Window/Object/Monster.h"
#include "../HyunsoonEngine_Window/Component/LandMonsterScript.h"
#include "../Object/Portal.h"
#include "../Object/GreenSnail.h"
#include "../Object/Background.h"

extern hs::Application app;

namespace hs
{
	AlterOfZakumEnt::AlterOfZakumEnt()
		: Scene(eSceneType::Hunting)
	{
	}

	AlterOfZakumEnt::~AlterOfZakumEnt()
	{
	}

	void AlterOfZakumEnt::Initialize()
	{
		// CamLimit
		Scene::SetCamLimit({ 2800, 700 });

		Background* larva = object::Instantiate<Background>();
		larva->SetRatioRender(true);
		larva->SetTexture(L"bg_Alter");

		Background* terrain = object::Instantiate<Background>();
		terrain->SetTexture(L"bg_AlterOfZakumEnt");

		GameObject*		   layer = object::Instantiate<GameObject>(eLayerType::Npc);
		graphics::Texture* layerTex = ResourceManager::Find<graphics::Texture>(L"bg_AlterOfZakumEntLayer");
		layer->GetComponent<Transform>()->SetPosition(layerTex->GetResolution());
		SpriteRenderer* spr = layer->AddComponent<SpriteRenderer>();
		spr->SetTexture(layerTex);

		Background* pillar = object::Instantiate<Background>(enums::eLayerType::Npc);
		pillar->SetTexture(L"bg_Pillar");
		pillar->SetPosition({ 1800, 600 });

		// Portal
		Portal* portal0 = object::Instantiate<Portal>({ 300, 512 });
		portal0->SetName(L"ZakumRoad");
		portal0->SetDestPortalIdx(1);

		Portal* portal1 = object::Instantiate<Portal>({ 2600, 512 });
		portal1->SetName(L"AlterOfZakum");
		portal1->SetDestPortalIdx(0);
	}
	void AlterOfZakumEnt::OnEnter()
	{
		Player*	   player = Player::GetInstance();
		Transform* tr = player->GetComponent<Transform>();
		Vector2	   pos = Vector2(800.0f, 300.0f);
		tr->SetPosition(pos);
		AddGameObject(player, enums::eLayerType::Player);
	}

	void AlterOfZakumEnt::OnExit()
	{
		std::vector<GameObject*>& objs = GetLayer(enums::eLayerType::Player)->GetGameObjects();
		objs.erase(std::find(objs.begin(), objs.end(), Player::GetInstance()));
	}
} // namespace hs