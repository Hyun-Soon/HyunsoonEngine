#pragma once

#include "../Monster.h"

namespace hs
{
	namespace zakumArms
	{
		static const std::vector<Vector2> offsets = { {-220,-200}, {-220,-150}, {-220,-80}, {-220, 0}, {80,-200}, {130,-150}, {130,-80}, {130, 0} };
		static const std::vector<Vector2> sizes = { {211, 229}, {238, 229}, {264, 206}, {267, 203}, {213, 226}, {248, 234}, {273, 214}, {267, 203} };
	}

	class ZakumArm : public Monster
	{
	public:
		ZakumArm();
		~ZakumArm();

		virtual void Initialize() override;
		virtual void Update() override;

		void SetIndex(int8_t idx) { mIdx = idx; }
		void SetParent(GameObject* parent) { mParent = parent; }

	private:
		int8_t		mIdx;
		GameObject* mParent;
	};
} // namespace hs