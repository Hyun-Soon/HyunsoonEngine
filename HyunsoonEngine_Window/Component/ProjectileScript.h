#pragma once

#include <vector>

#include "Component/Script.h"

namespace hs
{
	class GameObject;

	class ProjectileScript : public Script
	{
	public:
		ProjectileScript();
		~ProjectileScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC& hdc) override;

		virtual void OnCollisionEnter(Collider* other);
		virtual void OnCollisionStay(Collider* other);
		virtual void OnCollisionExit(Collider* other);

	private:
		void setTarget(const Vector2& ownerPos, const Vector2& ownerDir, std::vector<GameObject*> gameObjects);

		GameObject* mTarget;
		float		mSpeed;
		float		mRange;
		Vector2		mDirection;
	};

} // namespace hs
