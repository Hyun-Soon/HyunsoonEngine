#pragma once

#include "Item.h"

namespace hs
{
	class Miscellaneous : public Item
	{
	public:
		Miscellaneous(uint8_t id, uint8_t initAmount);
		~Miscellaneous();

	private:
		uint8_t mAmount;
	};

} // namespace hs