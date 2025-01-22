#pragma once

#include <Windows.h>

#include "Entity.h"

namespace hs
{
	class GameObject;
	class Component : public Entity
	{
	public:
		Component();
		~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC& hdc);

		void		SetOwner(GameObject* owner) { mOwner = owner; };
		GameObject* GetOwner() { return mOwner; }

	private:
		GameObject* mOwner;
	};
} // namespace hs
