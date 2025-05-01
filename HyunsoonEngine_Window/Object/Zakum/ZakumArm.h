#pragma once

#include "../Monster.h"

namespace hs
{
	class ZakumArm : public Monster
	{
	public:
		ZakumArm();
		~ZakumArm();

		virtual void Initialize() override;
		virtual void Update() override;

		void SetIndex(int8_t idx) { mIdx = idx; }
		void SetParent(GameObject* parent) { mParent = parent; }
		int8_t GetIndex() const { return mIdx; }

	private:
		int8_t		mIdx;
		GameObject* mParent;
	};
} // namespace hs