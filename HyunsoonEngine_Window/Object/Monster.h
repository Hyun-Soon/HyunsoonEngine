#pragma once

#include "GameObject/GameObject.h"

namespace hs
{
#define IDLE 0
#define MOVE 1
#define DEAD 2
	class Monster : public GameObject
	{
	public:
		// Why error occured if use enum class for constructor parameter?
		// enum class eMonsterState
		//{
		//	Idle, Move, Dead,
		//};

		Monster(Vector2 pos, bool dir, int state, uint16_t hp);
		~Monster();

		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC& hdc) override;

		void Attack();
		void TakeDamage(uint32_t damage);

	private:
		bool isPlayerNearby();

		bool	 bDirection;
		int		 mState;
		uint16_t mHP;
	};
} // namespace hs