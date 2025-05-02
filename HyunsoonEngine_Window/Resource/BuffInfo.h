#pragma once

#include <unordered_map>
#include <string>

namespace hs
{
	namespace buff
	{
		struct BuffInfo
		{
			std::wstring buffName;
			Vector2		 imgSize;
			UINT		 spriteLength;
			Vector2		 offset;

			BuffInfo() {};
			BuffInfo(std::wstring name, Vector2 size, UINT len, Vector2 offs)
				: buffName(name), imgSize(size), spriteLength(len), offset(offs) {};
		};

		enum class eBuff : unsigned short
		{
			CannotJump = 1,
			AccuracyDrop = 2,
			SkillLock = 4,
			End,
		};
	}
}