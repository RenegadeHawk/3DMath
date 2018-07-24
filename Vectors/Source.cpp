#include "Vector3.h"
const float Deg2Rad = 0.0174533;
const float Rad2Deg = 57.2958;
int main(void)
{
	
	Vector3 v0(2, 2, 1);
	std::cout <<"Vector v0 = "<<v0<<std::endl;
	Vector3 v1;
	std::cout << "Enter second vector"<<std::endl;
	std::cin >> v1;
	std::cout << "Vector v1 = " << v1 <<std::endl;
	std::cout << "sum of the two vectors = " << v0 + v1 << std::endl;
	std::cout << "Dot product of the two vectors = " << v0 * v1 << std::endl;
	std::cout << "Cross product of the two vectors = " << Cross(v0 ,v1) << std::endl;
	std::cout << "Angle between the two vectors = " << Angle(v0,v1) << std::endl;
	std::cout << "";


	
	std::cin.get();
	std::cin.get();
	return 0;
}