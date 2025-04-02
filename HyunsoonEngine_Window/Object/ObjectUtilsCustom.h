#pragma once

#include "Scene/SceneManager.h"
#include "Component/Transform.h"
#include "Projectile.h"

namespace hs
{
	namespace object
	{
		static Projectile* InstantiateProjectile(GameObject* caster)
		{
			Projectile* gameObj = new Projectile();
			gameObj->SetCaster(caster);
			gameObj->SetLayerType(enums::eLayerType::Projectile);
			gameObj->Initialize();
			SceneManager::AddGameObject(gameObj, enums::eLayerType::Projectile);

			Transform* tr = gameObj->GetComponent<Transform>();
			tr->SetPosition(caster->GetComponent<Transform>()->GetCenterPosition());

			return gameObj;
		}
	} // namespace object
} // namespace hs
