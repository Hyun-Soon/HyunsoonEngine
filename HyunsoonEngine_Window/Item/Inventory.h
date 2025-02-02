#pragma once

#include <list>

#include "Equipment.h"
#include "Consumables.h"
#include "Miscellaneous.h"

namespace hs
{
	class Shuriken;

	class Inventory
	{
	public:
		static Inventory* GetInstance();
		Shuriken* findShuriken();

	private:
		Inventory();
		~Inventory();

		static Inventory inventory;

		std::list<Equipment*>	  mEquipments;
		std::list<Consumables*>	  mConsumables;
		std::list<Miscellaneous*> mMiscellaneous;
		uint8_t					  mInventoryCapacity;
		uint32_t				  mMesoAmount;
	};

} // namespace hs
