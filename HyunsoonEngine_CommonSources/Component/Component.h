#pragma once

#include "../Entity.h"
#include "../Enums/Enums.h"

namespace hs
{
	class GameObject;
	class Component : public Entity
	{
	public:
		Component(enums::eComponentType type);
		~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC& hdc);

		void				  SetOwner(GameObject* owner) { mOwner = owner; };
		GameObject*			  GetOwner() const { return mOwner; }
		enums::eComponentType GetType() const { return mType; }

	private:
		enums::eComponentType mType;
		GameObject*			  mOwner;
	};
} // namespace hs
