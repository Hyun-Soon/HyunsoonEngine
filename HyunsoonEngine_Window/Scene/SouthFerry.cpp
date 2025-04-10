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
		Background* bg = object::Instantiate<Background>();
		bg->SetTexture(L"bg_SouthFerry");

		// Player
		//  It will be executed in Scene::Enter() func later
		Player*	   player = Player::GetInstance();
		Transform* tr = player->GetComponent<Transform>();
		Vector2	   pos = Vector2(800.0f, 300.0f);
		tr->SetPosition(pos);
		AddGameObject(player, enums::eLayerType::Player);

		// main camera
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::Background, Vector2(600.0f, 100.0f));
		Camera*		cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;
		cameraComp->SetTarget(player);

		// Portal
		// Portal* portal = object::Instantiate<Portal>({ 1450, 570 });
	}
} // namespace hs