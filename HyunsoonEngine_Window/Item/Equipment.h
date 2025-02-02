#pragma once

#include "Item.h"

namespace hs
{
	class Equipment : public Item
	{
	public:
		Equipment(eItemId id, uint8_t part);
		~Equipment();

	private:
		bool	mbEquipped;
		uint8_t mPart;
	};

} // namespace hs