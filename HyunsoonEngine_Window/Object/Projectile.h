#pragma once

#include "GameObject/GameObject.h"

namespace hs
{
	class Projectile : public GameObject
	{
	public:
		Projectile();
		~Projectile();

		virtual void Initialize() override;

		void		SetCaster(GameObject* caster) { mCaster = caster; }
		GameObject* GetCaster() const { return mCaster; }

	private:
		GameObject* mCaster;
	};

} // namespace hs