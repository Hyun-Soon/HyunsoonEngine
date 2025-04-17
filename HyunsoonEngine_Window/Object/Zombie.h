#pragma once

#include "Monster.h"

namespace hs
{
	class Zombie : public Monster
	{
	public:
		Zombie();
		~Zombie();

		virtual void Initialize() override;

	private:
	};
} // namespace hs