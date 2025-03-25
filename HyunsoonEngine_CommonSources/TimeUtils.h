#pragma once

#include <Windows.h>
#include <corecrt_wstdio.h>

namespace hs
{
	class TimeUtils
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

		__forceinline static float GetDeltaTime() { return DeltaTimeValue; };

	private:
		static LARGE_INTEGER CpuFrequency;
		static LARGE_INTEGER PrevFrequency;
		static LARGE_INTEGER CurrentFrequency;
		static float		 DeltaTimeValue;
	};
} // namespace hs
