#pragma once

#include <cstdint>
#include <Windows.h>

#include "PhysicsTypes.h"

namespace hs
{
	class Item
	{
	public:
		Item(uint8_t id);
		~Item();

		virtual void Update();
		virtual void Render(HDC& hdc);

	private:
		const uint8_t mId;
		Position	  mPos;
	};
} // namespace hs
