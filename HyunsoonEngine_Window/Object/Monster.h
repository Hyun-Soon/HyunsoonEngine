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
			End,
		};

		Monster();
		~Monster();

		/*void Attack();
		void TakeDamage(uint32_t damage);*/
		void		  SetState(eMonsterState state);
		eMonsterState GetState() const;
		float		  GetSpeed() const;

	private:
		// bool isPlayerNearby();

		Vector2		  bDirection;
		eMonsterState mState;
		float		  mSpeed;
		// uint16_t	  mHP;
	};
} // namespace hs