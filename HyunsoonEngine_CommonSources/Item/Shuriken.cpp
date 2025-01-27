#include "Item/Shuriken.h"

namespace hs
{
	Shuriken::Shuriken()
		: Consumables(Item::eItemId::Shuriken, 200)
		, mPower(25)
	{
	}

	Shuriken::~Shuriken()
	{
	}
	const uint8_t Shuriken::GetPower() const
	{
		return mPower;
	}
} // namespace hs