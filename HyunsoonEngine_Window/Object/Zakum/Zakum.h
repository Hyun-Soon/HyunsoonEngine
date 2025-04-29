#pragma once

#include "../Monster.h"
#include "ZakumArm.h"

namespace hs
{
	class Zakum : public Monster
	{
	public:
		Zakum();
		~Zakum();

		virtual void Initialize() override;
		//virtual void Update() override;
		//virtual void LateUpdate() override;
		//virtual void Render(HDC& hdc) override;

	private:
		const int mArmNum;
		//std::vector<ZakumArm*> mArms;
	};
} // namespace hs