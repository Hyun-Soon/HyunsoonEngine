#pragma once

#include <unordered_map>
#include <string>

#include "MathTypes.h"
#include "Input/Input.h"

namespace std
{
	template <>
	struct hash<::hs::Vector2>
	{
		size_t operator()(const ::hs::Vector2& v) const noexcept
		{
			return std::hash<int>()(v.x) ^ (std::hash<int>()(v.y) << 1);
		}
	};
} // namespace std

namespace hs
{
	static std::unordered_map<Vector2, std::wstring> dirStrMap = {
		{ Vector2::Left, L"_L" },
		{ Vector2::Right, L"_R" }
	};

	static std::unordered_map<eKeyCode, Vector2> keyDirMap = {
		{ eKeyCode::Left, Vector2::Left },
		{ eKeyCode::Right, Vector2::Right }
	};

} // namespace hs
