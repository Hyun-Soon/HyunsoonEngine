#include "Scene.h"
#include "GameObject/Monster.h"
#include "GameObject/Player.h"

namespace hs
{
	Scene::Scene(eSceneType sceneType)
		: mSceneType(sceneType)
		, mLayers()
	{
		for (UINT i = 0; i < (UINT)eLayerType::End; i++)
		{
			mLayers.push_back(new Layer());
		}
	}

	Scene::~Scene()
	{
		for (Layer* layer : mLayers)
			delete layer;
	}

	void Scene::Initialize()
	{
		// for (UINT i = 0; i < (UINT)eLayerType::End; i++)
		//{
		//	mLayers.push_back(new Layer());
		// }
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

	void Scene::AddGameObject(GameObject* gameObject)
	{
		UINT layerLevel = (UINT)gameObject->GetLayerLevel();
		mLayers[layerLevel]->AddGameObject(gameObject);
	}

	const Scene::eSceneType Scene::GetType() const
	{
		return mSceneType;
	}

	Monster* Scene::FindNearestMonster(float range)
	{
		// Player* player = Player::GetInstance();

		// Vector2 playerPos = player->GetPosition();
		// Vector2 playerDir = player->GetDirection();

		// Monster* ret = nullptr;
		// float	 minDist = FLT_MAX;

		// find monster in Monster Layer
		// for (Monster* pMon : mMonsters)
		//{
		//	Vector2 monsterPos = pMon->GetPosition();

		//	if (playerDir.x < 0)
		//	{
		//		if (playerPos.x < monsterPos.x)
		//			continue;
		//	}
		//	else
		//	{
		//		if (playerPos.x > monsterPos.x)
		//			continue;
		//	}

		//	float dist = Vector2::Length(monsterPos, playerPos);
		//	if (abs(monsterPos.y - playerPos.y) < 100
		//		&& dist <= range
		//		&& dist < minDist)
		//	{
		//		ret = pMon;
		//		minDist = dist;
		//	}
		//}

		// return ret;
		return nullptr;
	}
} // namespace hs