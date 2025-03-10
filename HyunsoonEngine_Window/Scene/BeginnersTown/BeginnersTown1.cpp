#include "BeginnersTown1.h"
#include "../HyunsoonEngine_Window/Object/Player.h"
#include "GameObject/GameObject.h"
#include "Component/Transform.h"
#include "Component/SpriteRenderer.h"
#include "GameObject/ObjectUtils.h"
#include "Resource/ResourceManager.h"

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
		GameObject*		   background = object::Instantiate<GameObject>(enums::eLayerType::Background);
		SpriteRenderer*	   spr = background->AddComponent<SpriteRenderer>();
		graphics::Texture* bg = ResourceManager::Find<graphics::Texture>(L"bg_BeginnersTown1");
		spr->SetTexture(bg);

		// Player
		//  It will be executed in Scene::Enter() func later
		Player*	   player = Player::GetInstance();
		Transform* tr = player->GetComponent<Transform>();
		Vector2	   pos = Vector2(100.0f, 300.0f);
		tr->SetPosition(pos);
		AddGameObject(player, enums::eLayerType::Player);

		// Monster
		 //Monster* greenSnail 
	}
} // namespace hs