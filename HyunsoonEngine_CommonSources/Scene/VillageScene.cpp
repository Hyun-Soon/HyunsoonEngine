#include "VillageScene.h"
#include "Component/Transform.h"
#include "Component/SpriteRenderer.h"

namespace hs
{
	VillageScene::VillageScene()
		: Scene(eSceneType::Village)
	{
	}

	VillageScene::~VillageScene()
	{
	}

	void VillageScene::Initialize()
	{
		// test
		GameObject* obj;

		obj = new GameObject(eLayerType::Background);
		Transform* transform = obj->AddComponent<Transform>();
		Vector2	   pos = { 100.0f, 100.0f };
		transform->SetName(L"Transform");
		transform->SetPosition(pos);

		SpriteRenderer* spr = obj->AddComponent<SpriteRenderer>();
		spr->ImageLoad(L"C:/Users/Soon/Desktop/HyunsoonEngine/Resources/Southferry/SouthferryNotSprite/Map/SouthFerry.png");

		AddGameObject(obj);
	}

} // namespace hs
