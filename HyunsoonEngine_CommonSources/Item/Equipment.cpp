#include "Item/Equipment.h"

namespace hs
{
	Equipment::Equipment(eItemId id, uint8_t part)
		: Item(id)
		, mbEquipped(false)
		, mPart(part)
	{
	}

	Equipment::~Equipment()
	{
	}
} // namespace hs