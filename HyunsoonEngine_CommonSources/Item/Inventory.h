#pragma once

#include <list>

#include "Item/Equipment.h"
#include "Item/Consumables.h"
#include "Item/Miscellaneous.h"

namespace hs
{
	class Shuriken;

	class Inventory
	{
	public:
		static Inventory* GetInstance();
		Shuriken*		  findShuriken();

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
