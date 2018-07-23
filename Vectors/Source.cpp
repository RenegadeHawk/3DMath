#include <iostream>
#include "Vector3.h"

const float Deg2Rad = 0.0174533;
const float Rad2Deg = 57.2958;
int main(void)
{

	Vector3 v0(0, 0, 0);
	Vector3 v1(2,2, 0);
	Vector3 v3 = Lerp(v0, v1,0.5);
			
	std::cout << v3.x<<v3.y<<v3.z;
	
	std::cin.get();

	return 0;
}