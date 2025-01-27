#pragma once

#include "Item/Consumables.h"

namespace hs
{
	class Shuriken : public Consumables
	{
	public:
		Shuriken();
		~Shuriken();

		const uint8_t GetPower() const;

	private:
		uint8_t mPower;
	};

} // namespace hs
