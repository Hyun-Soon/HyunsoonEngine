#pragma once

#include "Skill.h"

namespace hs
{
	class LuckySeven : public Skill
	{
	public:
		LuckySeven();
		~LuckySeven();

		virtual void Cast() override;

	private:
		uint8_t mShurikenUsage;
		uint8_t mRange;
	};

} // namespace hs