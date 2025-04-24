#include "Component/Transform.h"
#include "Component/SpriteRenderer.h"
#include "GameObject/ObjectUtils.h"
#include "Resource/ResourceManager.h"
#include "Resource/Texture.h"
#include "Renderer.h"
#include "Application.h"

#include "AlterOfZakum.h"
#include "../HyunsoonEngine_Window/Object/Player.h"
#include "../HyunsoonEngine_Window/Object/Monster.h"
#include "../HyunsoonEngine_Window/Component/LandMonsterScript.h"
#include "../Object/Portal.h"
#include "../Object/JrBalrog.h"
#include "../Object/Background.h"

extern hs::Application app;

namespace hs
{
	AlterOfZakum::AlterOfZakum()
		: Scene(eSceneType::Hunting)
	{
	}

	AlterOfZakum::~AlterOfZakum()
	{
	}

	void AlterOfZakum::Initialize()
	{
		// CamLimit
		Scene::SetCamLimit({ 1214, 950 });

		Background* larva = object::Instantiate<Background>();
		larva->SetRatioRender(true);
		larva->SetTexture(L"bg_Alter");

		Background* bg = object::Instantiate<Background>();
		bg->SetTexture(L"bg_AlterOfZakum");

		// Player
		Player*	   player = Player::GetInstance();
		AddGameObject(player, enums::eLayerType::Player);

		//Monster
		JrBalrog* jrBalrog = object::Instantiate<JrBalrog>({ 800, 500 });

		// Portal
		Portal* portal = object::Instantiate<Portal>({ 200, 657 });
		portal->SetName(L"AlterOfZakumEnt");
		portal->SetDestPortalIdx(1);
	}
	void AlterOfZakum::OnEnter()
	{
		Player*	   player = Player::GetInstance();
		Transform* tr = player->GetComponent<Transform>();
		Vector2	   pos = Vector2(200.0f, 300.0f);
		tr->SetPosition(pos);
	}

	void AlterOfZakum::OnExit()
	{
	}
} // namespace hs