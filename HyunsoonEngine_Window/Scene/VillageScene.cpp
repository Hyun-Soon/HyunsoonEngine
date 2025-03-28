#include "VillageScene.h"
#include "Component/Transform.h"
#include "Component/SpriteRenderer.h"
#include "Resource/ResourceManager.h"
#include "GameObject/GameObject.h"

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
		//// test
		// GameObject* obj;

		// obj = new GameObject();
		// Transform* transform = obj->AddComponent<Transform>();
		// Vector2	   pos = { 0.0f, 0.0f };
		// transform->SetName(L"Transform");
		// transform->SetPosition(pos);

		// SpriteRenderer* spr = obj->AddComponent<SpriteRenderer>();

		// graphics::Texture* texture = ResourceManager::Load<graphics::Texture>(L"keyGuide", L"C:/Users/Soon/Desktop/HyunsoonEngine/Resources/BeginnersTown1/BeginnersTown1NotSprite/KeyGuide_Alt.png");
		// spr->SetTexture(texture);
		//// spr->ImageLoad(L"C:/Users/Soon/Desktop/HyunsoonEngine/Resources/Southferry/SouthferryNotSprite/Map/SouthFerry.png");

		// AddGameObject(obj, enums::eLayerType::Background);
	}

} // namespace hs
