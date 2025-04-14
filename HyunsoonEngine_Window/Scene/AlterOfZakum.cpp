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
#include "../Object/GreenSnail.h"
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
		Background* bg = object::Instantiate<Background>();
		bg->SetTexture(L"bg_AlterOfZakum");

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
	void AlterOfZakum::OnEnter()
	{
		Player*	   player = Player::GetInstance();
		Transform* tr = player->GetComponent<Transform>();
		Vector2	   pos = Vector2(800.0f, 300.0f);
		tr->SetPosition(pos);
	}

	void AlterOfZakum::OnExit()
	{
	}
} // namespace hs