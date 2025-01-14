#pragma once

#include "Entity.h"

namespace hs
{
	class Skill : public Entity
	{
	public:
		Skill();
		~Skill();

		virtual void Cast() = 0;

	private:
		uint16_t mCooldown;
	};
} // namespace hs
