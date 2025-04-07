#pragma once

#include "Monster.h"

namespace hs
{
	class GreenSnail : public Monster
	{
	public:
		GreenSnail();
		~GreenSnail();

		virtual void Initialize() override;

	private:
	};
} // namespace hs