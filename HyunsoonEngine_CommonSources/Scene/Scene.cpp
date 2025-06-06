#include "Scene.h"
#include "GameObject/GameObject.h"
#include "Application.h"

extern hs::Application app;

namespace hs
{
	Scene::Scene(eSceneType sceneType)
		: mSceneType(sceneType)
		, mLayers()
	{
		createLayers();
	}

	Scene::~Scene()
	{
		for (Layer* layer : mLayers)
			delete layer;
	}

	void Scene::Initialize()
	{
	}

	void Scene::Update()
	{
		for (Layer* layer : mLayers)
		{
			layer->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (Layer* layer : mLayers)
		{
			layer->LateUpdate();
		}
	}

	void Scene::Render(HDC& hdc)
	{
		for (Layer* layer : mLayers)
		{
			layer->Render(hdc);
		}
	}

	void Scene::Destroy()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->Destroy();
		}
	}

	void Scene::OnEnter()
	{
	}

	void Scene::OnExit()
	{
	}

	void Scene::AddGameObject(GameObject* gameObject)
	{
		mLayers[(UINT)gameObject->GetLayerType()]->AddGameObject(gameObject);
	}

	void Scene::AddGameObject(GameObject* gameObject, enums::eLayerType layerLevel)
	{
		mLayers[(UINT)layerLevel]->AddGameObject(gameObject);
	}

	void Scene::EraseGameObject(GameObject* gameObj)
	{
		enums::eLayerType layerType = gameObj->GetLayerType();
		mLayers[(UINT)layerType]->EraseGameObject(gameObj);
	}

	const Scene::eSceneType Scene::GetType() const
	{
		return mSceneType;
	}

	// Monster* Scene::FindNearestMonster(float range)
	//{
	//	// Player* player = Player::GetInstance();

	//	// Vector2 playerPos = player->GetPosition();
	//	// Vector2 playerDir = player->GetDirection();

	//	// Monster* ret = nullptr;
	//	// float	 minDist = FLT_MAX;

	//	// find monster in Monster Layer
	//	// for (Monster* pMon : mMonsters)
	//	//{
	//	//	Vector2 monsterPos = pMon->GetPosition();

	//	//	if (playerDir.x < 0)
	//	//	{
	//	//		if (playerPos.x < monsterPos.x)
	//	//			continue;
	//	//	}
	//	//	else
	//	//	{
	//	//		if (playerPos.x > monsterPos.x)
	//	//			continue;
	//	//	}

	//	//	float dist = Vector2::Length(monsterPos, playerPos);
	//	//	if (abs(monsterPos.y - playerPos.y) < 100
	//	//		&& dist <= range
	//	//		&& dist < minDist)
	//	//	{
	//	//		ret = pMon;
	//	//		minDist = dist;
	//	//	}
	//	//}

	//	// return ret;
	//	return nullptr;
	//}

	void Scene::createLayers()
	{
		UINT layerDepth = static_cast<UINT>(enums::eLayerType::End);
		mLayers.resize(layerDepth);
		for (size_t i = 0; i < layerDepth; i++)
		{
			mLayers[i] = new Layer();
		}
	}
} // namespace hs