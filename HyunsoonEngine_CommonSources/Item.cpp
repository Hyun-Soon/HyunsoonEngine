#include "Item.h"

namespace hs
{
	Item::Item(eItemId id)
		: mId(id)
		, mPos(0.0f, 0.0f)
	{
	}

	Item::~Item()
	{
	}

	void Item::Render(HDC& hdc)
	{
	}

	const Item::eItemId Item::GetId() const
	{
		return mId;
	}
} // namespace hs