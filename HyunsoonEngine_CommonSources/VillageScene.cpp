#include "VillageScene.h"
#include "Component/Transform.h"
#include "SpriteRenderer.h"

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
		// GameObject* obj;

		// obj = new GameObject(Layer::eLayerType::Background);
		// Transform* transform = obj->AddComponent<Transform>();
		// Vector2	   pos = { 100.0f, 100.0f };
		// transform->SetOwner(obj);
		// transform->SetPosition(pos);

		// SpriteRenderer* spr = obj->AddComponent<SpriteRenderer>();
		// spr->Initialize();
		// spr->SetOwner(obj);
		// spr->ImageLoad(L"C:/Users/Soon/Desktop/HyunsoonEngine/Resources/Southferry/SouthferryNotSprite/Map/SouthFerry.png");

		// AddGameObject(obj);
		//  obj = new Npc({ 500.0f, 0.0f });
		//  AddGameObject(pObj);
	}

} // namespace hs
