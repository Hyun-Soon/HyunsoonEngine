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
		Background* bg = object::Instantiate<Background>();
		bg->SetTexture(L"bg_AlterOfZakumEnt");

		// Player
		//  It will be executed in Scene::Enter() func later
		Player*	   player = Player::GetInstance();
		Transform* tr = player->GetComponent<Transform>();
		Vector2	   pos = Vector2(800.0f, 300.0f);
		tr->SetPosition(pos);
		AddGameObject(player, enums::eLayerType::Player);

		GameObject*		   layer = object::Instantiate<GameObject>(eLayerType::Npc);
		graphics::Texture* layerTex = ResourceManager::Find<graphics::Texture>(L"bg_AlterOfZakumEntLayer");
		layer->GetComponent<Transform>()->SetPosition(layerTex->GetResolution());
		SpriteRenderer* spr = layer->AddComponent<SpriteRenderer>();
		spr->SetTexture(layerTex);

		// Portal
		/*Portal* portal = object::Instantiate<Portal>({ 160, 1688 });
		portal->SetName(L"CrossRoad");
		portal->SetDestPortalIdx(1);*/
	}
	void AlterOfZakumEnt::OnEnter()
	{
		Player*	   player = Player::GetInstance();
		Transform* tr = player->GetComponent<Transform>();
		Vector2	   pos = Vector2(800.0f, 300.0f);
		tr->SetPosition(pos);
	}

	void AlterOfZakumEnt::OnExit()
	{
	}
} // namespace hs