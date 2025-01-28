#include "BeginnersTown1.h"
#include "GameObject/Player.h"
#include "GameObject/GameObject.h"
#include "Component/Transform.h"
#include "Component/SpriteRenderer.h"
#include "GameObject/ObjectUtils.h"

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
		GameObject*		background = object::Instantiate<GameObject>(enums::eLayerType::Background);
		SpriteRenderer* sr = background->AddComponent<SpriteRenderer>();
		sr->ImageLoad(L"../Resources/BeginnersTown1/BeginnersTown1NotSprite/BeginnersTown1/BeginnersTown1Background.png");

		// It will be executed in Scene::Enter() func later
		Player*	   player = Player::GetInstance();
		Transform* tr = player->GetComponent<Transform>();
		Vector2	   pos = Vector2(100.0f, 300.0f);
		tr->SetPosition(pos);
		AddGameObject(player, enums::eLayerType::Player);
	}
} // namespace hs