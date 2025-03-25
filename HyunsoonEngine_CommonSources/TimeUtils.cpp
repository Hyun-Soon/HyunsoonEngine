#include "TimeUtils.h"

namespace hs
{
	LARGE_INTEGER TimeUtils::CpuFrequency = {};
	LARGE_INTEGER TimeUtils::PrevFrequency = {};
	LARGE_INTEGER TimeUtils::CurrentFrequency = {};
	float		  TimeUtils::DeltaTimeValue = 0.0f;

	void TimeUtils::Initialize()
	{
		// 고해상도 타이머의 초당 틱(Ticks per second) 주기를 반환
		QueryPerformanceFrequency(&CpuFrequency);

		// 고해상도 타이머의 현재 카운터 값을 반환
		QueryPerformanceCounter(&PrevFrequency);
	}

	void TimeUtils::Update()
	{
		QueryPerformanceCounter(&CurrentFrequency);

		float differenceFrequency = static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);
		DeltaTimeValue = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart);
		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
	}

	void TimeUtils::Render(HDC hdc)
	{
		static float time = 0.0f;

		time += DeltaTimeValue;
		float fps = 1.0f / DeltaTimeValue;

		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"Time : %d", (int)fps);
		int len = wcsnlen_s(str, 50);

		TextOut(hdc, 0, 0, str, len);
	}

} // namespace hs
