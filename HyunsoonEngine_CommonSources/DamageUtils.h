#pragma once

#include <random>
#include <string>

class DamageUtils
{
public:
	static float CalculateDamage(float baseDamage)
	{
		std::random_device				   rd;		  // �õ� ������
		std::mt19937					   gen(rd()); // ���� ������
		int								   range = pow(9, (std::to_string(baseDamage).size()));
		std::uniform_int_distribution<int> dist(baseDamage - range, baseDamage + range); // �Ǽ� ���� ����

		return dist(gen); // ���� ����;
	}

private:
	DamageUtils();
	~DamageUtils();
};