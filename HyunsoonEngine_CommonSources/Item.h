#pragma once

#include <cstdint>
#include <Windows.h>

#include "MathTypes.h"

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
		Vector2		  mPos;
	};
} // namespace hs
