#pragma once

#include "Item/Item.h"

namespace hs
{
	class Consumables : public Item
	{
	public:
		Consumables(eItemId id, uint8_t initAmount);
		~Consumables();

		bool Use(uint8_t amount);

	private:
		uint8_t mAmount;
	};

} // namespace hs