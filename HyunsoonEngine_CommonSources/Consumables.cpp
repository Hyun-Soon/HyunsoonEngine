#include "Consumables.h"

namespace hs
{
	Consumables::Consumables(uint8_t id, uint8_t initAmount)
		: Item(id)
		, mAmount(initAmount)
	{
	}

	Consumables::~Consumables()
	{
	}

	bool Consumables::Use(uint8_t amount)
	{
		if (mAmount < amount)
		{
			mAmount = 0;
			return false;
		}

		mAmount -= amount;
		return true;
	}
} // namespace hs