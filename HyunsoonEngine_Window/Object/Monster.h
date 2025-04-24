#pragma once

#include "GameObject/GameObject.h"

namespace hs
{
	class Monster : public GameObject, public Entity
	{
	public:
		enum class eMonsterState
		{
			Idle,
			Move,
			Chase,
			Attacked,
			Attack,
			Dead,
			End,
		};

		Monster();
		~Monster();

		/*void Attack();
		void TakeDamage(uint32_t damage);*/
		void		  SetState(eMonsterState state);
		eMonsterState GetState() const;
		void		  SetSpeed(float speed) { mSpeed = speed; }
		float		  GetSpeed() const;

	private:
		// bool isPlayerNearby();

		Vector2		  bDirection;
		eMonsterState mState;
		float		  mSpeed;
	};
} // namespace hs