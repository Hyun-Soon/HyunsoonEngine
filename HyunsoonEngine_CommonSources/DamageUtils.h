#pragma once

#include <random>
#include <string>

class DamageUtils
{
public:
	static uint32_t CalculateDamage(uint32_t baseDamage)
	{
		std::random_device				   rd;		  // 시드 생성기
		std::mt19937					   gen(rd()); // 난수 생성기
		uint32_t						   range = pow(9, (std::to_string(baseDamage).size()));
		std::uniform_int_distribution<int> dist(baseDamage - range, baseDamage + range); // 실수 범위 설정

		return dist(gen); // 난수 생성;
	}

private:
	DamageUtils();
	~DamageUtils();
};