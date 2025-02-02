#pragma once

#include "Item.h"

namespace hs
{
	class Miscellaneous : public Item
	{
	public:
		Miscellaneous(eItemId id, uint8_t initAmount);
		~Miscellaneous();

	private:
		uint8_t mAmount;
	};

} // namespace hs