#include "Inventory.h"

namespace hs
{
	Inventory::Inventory()
		: mEquipments()
		, mConsumables()
		, mMiscellaneous()
		, mInventoryCapacity(24)
		, mMesoAmount(0)
	{
	}

	Inventory::~Inventory()
	{
	}
} // namespace hs