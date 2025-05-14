#include "../Object/Player.h"
#include "../Object/Monster.h"
#include "Component/Transform.h"
#include "../Object/Projectile.h"
#include "ProjectileScript.h"
#include "Scene/SceneManager.h"
#include "../Component/PlayerScript.h"
#include "../Component/LandMonsterScript.h"
#include "RandomUtils.h"
#include "../Resource/BuffInfo.h"

namespace hs
{
	ProjectileScript::ProjectileScript()
		: mTarget(nullptr)
		, mSpeed(0.0f)
		, mRange(0.0f)
		, mDirection(Vector2::Zero)
		, mDamage(0)
	{
	}

	ProjectileScript::~ProjectileScript()
	{
	}

	void ProjectileScript::Initialize()
	{
		mSpeed = 200.0f;
		mRange = 500.0f;
		GameObject*		  caster = static_cast<Projectile*>(GetOwner())->GetCaster();
		enums::eLayerType casterType = caster->GetLayerType();
		Vector2			  casterPos = caster->GetComponent<Transform>()->GetPosition();
		Vector2			  casterDir;
		enums::eLayerType targetType;

		if (casterType == enums::eLayerType::Player)
		{
			targetType = enums::eLayerType::Monster;
			casterDir = static_cast<Player*>(caster)->GetComponent<PlayerScript>()->GetDirection();
		}
		else //(casterType == enums::eLayerType::Monster)
		{
			targetType = enums::eLayerType::Player;
			casterDir = static_cast<Monster*>(caster)->GetComponent<LandMonsterScript>()->GetDirection();
		}

		std::vector<GameObject*> targetObjects = SceneManager::GetActiveScene()->GetLayer(targetType)->GetGameObjects();

		setTarget(casterPos, casterDir, targetObjects);

		if (mTarget == nullptr)
		{
			Rigidbody* rgb = GetOwner()->GetComponent<Rigidbody>();
			rgb->SetVelocity(casterDir * mSpeed);
		}

		if (casterDir.x < 0)
			GetOwner()->GetComponent<Animator>()->PlayAnimation(L"Shuriken_L");
		else
			GetOwner()->GetComponent<Animator>()->PlayAnimation(L"Shuriken_R");
	}

	void ProjectileScript::Update()
	{
		if (mTarget == nullptr)
			return;

		Vector2 projectilePos = GetOwner()->GetComponent<Transform>()->GetPosition();
		Vector2 targetPos = mTarget->GetComponent<Transform>()->GetPosition();
		Vector2 velocity = targetPos - projectilePos;

		velocity.Normalize();
		velocity *= mSpeed;

		GetOwner()->GetComponent<Rigidbody>()->SetVelocity(velocity);
	}

	void ProjectileScript::LateUpdate()
	{
	}

	void ProjectileScript::Render(HDC& hdc)
	{
	}

	void ProjectileScript::OnCollisionEnter(Collider* other)
	{
		object::Destroy(GetOwner());
	}

	void ProjectileScript::OnCollisionStay(Collider* other)
	{
	}

	void ProjectileScript::OnCollisionExit(Collider* other)
	{
	}

	UINT ProjectileScript::GetRandomDamage()
	{
		if (Player::GetInstance()->GetComponent<PlayerScript>()->IsBuffOn(static_cast<unsigned short>(buff::eBuff::AccuracyDrop)))
			return 0;
		float half = mDamage / 2.0f;
		return RandomUtils::GetRandomValueInt(half, mDamage + half);
	}

	void ProjectileScript::setTarget(const Vector2& casterPos, const Vector2& casterDir, std::vector<GameObject*> gameObjects)
	{
		GameObject* target = nullptr;

		for (GameObject* obj : gameObjects)
		{
			if (obj == nullptr)
				continue;

			Vector2 objPos = obj->GetComponent<Transform>()->GetCenterPosition();

			if (Player::GetInstance()->GetComponent<PlayerScript>()->GetDirection() == Vector2::Left && objPos.x > Player::GetInstance()->GetComponent<Transform>()->GetPosition().x)
				continue;
			if (Player::GetInstance()->GetComponent<PlayerScript>()->GetDirection() == Vector2::Right && objPos.x < Player::GetInstance()->GetComponent<Transform>()->GetPosition().x)
				continue;
			if (Vector2::Length(casterPos, objPos) > mRange)
				continue;

			if (target == nullptr)
			{
				if (casterPos.x < objPos.x && casterDir.x > 0)
					target = obj;
				else if (casterPos.x > objPos.x && casterDir.x < 0)
					target = obj;
			}
			else
			{
				Vector2 targetPos = target->GetComponent<Transform>()->GetPosition();
				if (casterDir.x > 0 && casterPos.x < objPos.x && objPos.x < targetPos.x)
					target = obj;
				else if (casterDir.x < 0 && casterPos.x > objPos.x && objPos.x > targetPos.x)
					target = obj;
			}
		}

		mTarget = target;
	}
} // namespace hs
