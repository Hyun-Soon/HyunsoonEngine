#pragma once

#include "Monster.h"

namespace hs
{
	class Spore : public Monster
	{
	public:
		Spore();
		~Spore();

		virtual void Initialize() override;

	private:
	};
} // namespace hs