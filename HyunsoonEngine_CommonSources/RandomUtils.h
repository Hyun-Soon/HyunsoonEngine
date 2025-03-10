#pragma once

#include <string>
#include <random>

namespace hs
{
	class RandomUtils
	{
	public:
		RandomUtils();
		~RandomUtils();

		static std::wstring GetRandomValueWString(int minVal, int maxVal);
		static int			GetRandomValueInt(int minVal, int maxVal);

	private:
		static std::random_device rd;  // 하드웨어 난수 생성기
		static std::mt19937		  gen; // Mersenne Twister 엔진
	};

} // namespace hs
