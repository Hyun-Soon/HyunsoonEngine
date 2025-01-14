#pragma once

#include "Item.h"

namespace hs
{
	class Consumables : public Item
	{
	public:
		Consumables(uint8_t id, uint8_t initAmount);
		~Consumables();

		bool Use(uint8_t amount);

	private:
		uint8_t mAmount;
	};

} // namespace hs