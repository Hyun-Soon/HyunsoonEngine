#include "Item.h"

namespace hs
{
	Item::Item(uint8_t id)
		: mId(id)
		, mPos(0.0f, 0.0f)
	{
	}

	Item::~Item()
	{
	}

	void Item::Update()
	{
	}

	void Item::Render(HDC& hdc)
	{
	}
} // namespace hs