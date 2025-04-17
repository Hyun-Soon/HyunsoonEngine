#pragma once

#include "Monster.h"

namespace hs
{
	class BlueSnail : public Monster
	{
	public:
		BlueSnail();
		~BlueSnail();

		virtual void Initialize() override;

	private:
	};
} // namespace hs