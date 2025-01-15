#pragma once

#include <random>
#include <string>

class DamageUtils
{
public:
	static uint32_t CalculateDamage(uint32_t baseDamage)
	{
		std::random_device				   rd;		  // �õ� ������
		std::mt19937					   gen(rd()); // ���� ������
		uint32_t						   range = pow(9, (std::to_string(baseDamage).size()));
		std::uniform_int_distribution<int> dist(baseDamage - range, baseDamage + range); // �Ǽ� ���� ����

		return dist(gen); // ���� ����;
	}

private:
	DamageUtils();
	~DamageUtils();
};