#pragma once

#include "GameObject/ObjectUtils.h"
#include "GameObject/GameObject.h"
#include "../Item/Inventory.h"

namespace hs
{
	static class Player : public GameObject
	{
	public:
		enum class ePlayerState : short
		{
			Idle = 1,
			Move = 2,
			Attack = 4,
			LyingDown = 8,
			Dead = 16,
			Jump = 32,
			DoubleJump = 64,
			Alert = 128,
			End,
		};

		enum class ePlayerBuff : unsigned short
		{
			CannotJump = 1,
			AccuracyDrop = 2,
			SkillLock = 4,
			End,
		};

		static Player* GetInstance();

		virtual void Initialize() override;

		const ePlayerState GetState() const;
		void			   SetState(ePlayerState state);

	private:
		Player();
		~Player();

		static Player* player;

		ePlayerState			mState;
		uint16_t				mHP;
		uint16_t				mMP;

		template <typename T>
		friend static T* Instantiate(hs::enums::eLayerType layerLevel);
	};

} // namespace hs