#include "Component/Transform.h"
#include "Component/SpriteRenderer.h"
#include "GameObject/ObjectUtils.h"
#include "Resource/ResourceManager.h"
#include "Renderer.h"
#include "Application.h"

#include "BeginnersTown1.h"
#include "../HyunsoonEngine_Window/Object/Player.h"
#include "../HyunsoonEngine_Window/Object/Monster.h"
#include "../HyunsoonEngine_Window/Component/LandMonsterScript.h"

extern hs::Application app;

namespace hs
{
	BeginnersTown1::BeginnersTown1()
		: Scene(eSceneType::Hunting)
	{
	}

	BeginnersTown1::~BeginnersTown1()
	{
	}

	void BeginnersTown1::Initialize()
	{
		GameObject* background = object::Instantiate<GameObject>(enums::eLayerType::Background);
		Transform*	tr_bg = background->GetComponent<Transform>();
		tr_bg->SetPosition(app.GetResolution());
		SpriteRenderer*	   spr = background->AddComponent<SpriteRenderer>();
		graphics::Texture* bg = ResourceManager::Find<graphics::Texture>(L"bg_BeginnersTown1");
		spr->SetTexture(bg);

		// main camera
		// GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(600.0f, 0.0f));
		// Camera*		cameraComp = camera->AddComponent<Camera>();
		// renderer::mainCamera = cameraComp;

		// Player
		//  It will be executed in Scene::Enter() func later
		Player*	   player = Player::GetInstance();
		Transform* tr = player->GetComponent<Transform>();
		Vector2	   pos = Vector2(100.0f, 300.0f);
		tr->SetPosition(pos);
		AddGameObject(player, enums::eLayerType::Player);

		// Monster
		Monster* greenSnail = object::Instantiate<Monster>(enums::eLayerType::Monster);
		greenSnail->SetName(L"GreenSnail");
		Transform* tr_greenSnail = greenSnail->GetComponent<Transform>();
		tr_greenSnail->SetPosition({ 300.0f, 500.0f });
		Rigidbody* rgb_greenSnail = greenSnail->AddComponent<Rigidbody>();
		rgb_greenSnail->SetGravity(true);
		Animator*		   anim_greenSnail = greenSnail->AddComponent<Animator>();
		graphics::Texture* greenSnailIdle_L = ResourceManager::Find<graphics::Texture>(L"GreenSnailIdle_L");
		anim_greenSnail->CreateAnimation(L"GreenSnailIdle_L", greenSnailIdle_L, Vector2::Zero, { 37, 26 }, Vector2::Zero, 1, 10);
		graphics::Texture* greenSnailIdle_R = ResourceManager::Find<graphics::Texture>(L"GreenSnailIdle_R");
		anim_greenSnail->CreateAnimation(L"GreenSnailIdle_R", greenSnailIdle_R, Vector2::Zero, { 37, 26 }, Vector2::Zero, 1, 10);
		graphics::Texture* greenSnailMove_L = ResourceManager::Find<graphics::Texture>(L"GreenSnailMove_L");
		anim_greenSnail->CreateAnimation(L"GreenSnailMove_L", greenSnailMove_L, Vector2::Zero, { 37, 26 }, Vector2::Zero, 8, 0.3f);
		graphics::Texture* greenSnailMove_R = ResourceManager::Find<graphics::Texture>(L"GreenSnailMove_R");
		anim_greenSnail->CreateAnimation(L"GreenSnailMove_R", greenSnailMove_R, Vector2::Zero, { 37, 26 }, Vector2::Zero, 8, 0.3f);
		graphics::Texture* greenSnailAttacked_L = ResourceManager::Find<graphics::Texture>(L"GreenSnailAttacked_L");
		anim_greenSnail->CreateAnimation(L"GreenSnailAttacked_L", greenSnailAttacked_L, Vector2::Zero, { 43, 33 }, Vector2::Zero, 1, 10);
		graphics::Texture* greenSnailAttacked_R = ResourceManager::Find<graphics::Texture>(L"GreenSnailAttacked_R");
		anim_greenSnail->CreateAnimation(L"GreenSnailAttacked_R", greenSnailAttacked_R, Vector2::Zero, { 43, 33 }, Vector2::Zero, 1, 10);
		graphics::Texture* greenSnailDeath_L = ResourceManager::Find<graphics::Texture>(L"GreenSnailDeath_L");
		anim_greenSnail->CreateAnimation(L"GreenSnailDeath_L", greenSnailDeath_L, Vector2::Zero, { 44, 33 }, Vector2::Zero, 9, 0.1f);
		graphics::Texture* greenSnailDeath_R = ResourceManager::Find<graphics::Texture>(L"GreenSnailDeath_R");
		anim_greenSnail->CreateAnimation(L"GreenSnailDeath_R", greenSnailDeath_R, Vector2::Zero, { 44, 33 }, Vector2::Zero, 9, 0.1f);
		anim_greenSnail->PlayAnimation(L"GreenSnailIdle_L");
		LandMonsterScript* lms_greenSnail = greenSnail->AddComponent<LandMonsterScript>();
	}
} // namespace hs