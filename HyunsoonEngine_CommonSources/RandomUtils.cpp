#include "RandomUtils.h"

namespace hs
{
	std::random_device RandomUtils::rd;
	std::mt19937	   RandomUtils::gen(rd());

	RandomUtils::RandomUtils()
	{
	}

	RandomUtils::~RandomUtils()
	{
	}

	std::wstring RandomUtils::GetRandomValueWString(int minVal, int maxVal)
	{

		std::uniform_int_distribution<int> dist(minVal, maxVal); // ±Õµî ºÐÆ÷
		int								   ret = dist(gen);

		return std::to_wstring(ret);
	}

	int RandomUtils::GetRandomValueInt(int minVal, int maxVal)
	{

		std::uniform_int_distribution<int> dist(minVal, maxVal);
		return dist(gen);
	}
} // namespace hs