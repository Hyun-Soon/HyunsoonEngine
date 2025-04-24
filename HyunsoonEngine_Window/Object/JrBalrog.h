#pragma once

#include "Monster.h"

namespace hs
{
	class JrBalrog : public Monster
	{
	public:
		JrBalrog();
		~JrBalrog();

		virtual void Initialize() override;

	private:
	};
} // namespace hs