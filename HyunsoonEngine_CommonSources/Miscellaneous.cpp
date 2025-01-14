#include "Miscellaneous.h"

namespace hs
{
	Miscellaneous::Miscellaneous(uint8_t id, uint8_t initAmount)
		: Item(id)
		, mAmount(initAmount)
	{
	}

	Miscellaneous::~Miscellaneous()
	{
	}
} // namespace hs