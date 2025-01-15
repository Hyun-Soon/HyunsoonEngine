#pragma once

#include <cstdint>
#include <Windows.h>

#include "PhysicsTypes.h"

namespace hs
{
	class Item
	{
	public:
		enum class eItemId
		{
			Meso,
			Shuriken,
		};
		Item(eItemId id);
		~Item();

		virtual void Render(HDC& hdc);

		const eItemId GetId() const;

	private:
		const eItemId mId;
		Position	  mPos;
	};
} // namespace hs
