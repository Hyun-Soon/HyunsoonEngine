#include "Miscellaneous.h"

namespace hs
{
	Miscellaneous::Miscellaneous(eItemId id, uint8_t initAmount)
		: Item(id)
		, mAmount(initAmount)
	{
	}

	Miscellaneous::~Miscellaneous()
	{
	}
} // namespace hs