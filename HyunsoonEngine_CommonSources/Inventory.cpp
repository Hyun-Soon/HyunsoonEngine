#include "Inventory.h"
#include "Shuriken.h"

namespace hs
{
	Inventory Inventory::inventory;

	Inventory* Inventory::GetInstance()
	{
		return &inventory;
	}

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

	Shuriken* Inventory::findShuriken()
	{
		for (Consumables* consumable : mConsumables)
			if (consumable->GetId() == Item::eItemId::Shuriken)
				return static_cast<Shuriken*>(consumable);
		return nullptr;
	}
} // namespace hs