#pragma once

#include "Monster.h"

namespace hs
{
	class OrangeMushroom : public Monster
	{
	public:
		OrangeMushroom();
		~OrangeMushroom();

		virtual void Initialize() override;

	private:
	};
} // namespace hs