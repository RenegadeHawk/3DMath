#include "Vector3.h"
const float Deg2Rad = 0.0174533;
const float Rad2Deg = 57.2958;
int main(void)
{
	int a = 2;
	Vector3 v0(2, 2, 1);
	std::cout << v0;
	Vector3 v1(0, 3, 0);
	Vector3 v3;
	v3 = v0 * 2;
	std::cout << "";


	
	std::cin.get();

	return 0;
}