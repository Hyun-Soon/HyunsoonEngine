#include "Equipment.h"

namespace hs
{
	Equipment::Equipment(uint8_t id, uint8_t part)
		: Item(id)
		, mbEquipped(false)
		, mPart(part)
	{
	}

	Equipment::~Equipment()
	{
	}
} // namespace hs