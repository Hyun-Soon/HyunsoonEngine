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

		static std::unordered_map<unsigned short, BuffInfo> buffInfoMap = {
			{ 1, { L"CannotJump", { 43, 41 }, 6, { 0, -60 } } },
			{ 2, { L"AccuracyDrop", { 48, 52 }, 7, { 10, -80 } } },
			{ 4, { L"SkillLock", { 73, 47 }, 10, { -20, -80 } } }
		};
	}
}