#pragma once

#include "GameObject.h"

namespace hs
{
#define IDLE 0
#define MOVE 1
#define DEAD 2
	class Monster : public GameObject
	{
	public:
		// Why error occured if use enum class for constructor parameter?
		//enum class eMonsterState
		//{
		//	Idle, Move, Dead,
		//};

		Monster(bool dir, int state, uint16_t hp);
		~Monster();

		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC& hdc) override;

		void Attack();

	private:


		bool isPlayerNearby();

		bool bDirection;
		int mState;
		uint16_t mHP;
	};
}