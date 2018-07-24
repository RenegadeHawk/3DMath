#pragma once
#include <exception>
#include <iostream>
class Vector3
{
private:
	

public:

	/*Initializing*/

	//individual values
	float x, y, z;
	//default constructor
	Vector3() {}
	//default destructor
	~Vector3();
	//constructor with given values
	Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
	//copy constructor 
	Vector3(const Vector3 &v) : x(v.x),y(v.y),z(v.z){}
	
	//Equality Check
	bool operator == (const Vector3 &v)
	{
		return(x == v.x && y == v.y && z == v.z);
	}
	//Inequality Check
	bool operator != (const Vector3 &v)
	{
		return(x != v.x || y != v.y || z != v.z);
	}
	/*Vector Operations*/

	// + operator (addition)
	Vector3 operator+ (const Vector3 &v) 
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}
	// - operator (subtraction)
	Vector3 operator- (const Vector3 &v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}
	// normalization
	Vector3 normalized() const
	{
		float magnitude = x*x + y*y + z*z;			
		if (magnitude > 0)							// checking for divide by zero
		{
			float root = sqrt(magnitude);			
			root = 1 / root;						//one by square root of sqr magnitude
			return Vector3(x* root, y* root, z* root);
		}
	}
	//magnitude
	float magnitude() const
	{
		return sqrt(x*x + y*y + z*z);
	}
	//scalar multiplication
	Vector3 operator * (float f) const
	{
		return Vector3(x*f, y*f, z*f);
	}
	//scalar division
	Vector3 operator / (float f) const
	{
		return Vector3(x/f, y/f, z/f);
	}
	//Dot product
	float operator * (const Vector3 &a)
	{
		return (x*a.x + y*a.y + z*a.z);
	}
	
	/*Overloading I/O operators*/

	//Overloading output stream operator
	friend std::ostream& operator<<(std::ostream& os, const Vector3& v)
	{
		os <<'(' <<v.x << ',' << v.y << ',' << v.z<<')';
		return os;
	}

	//Overloading input stream operator
	friend std::istream &operator>>(std::istream  &is, Vector3& v) {
		is >> v.x >> v.y >> v.z;
		return is;
	}
};
	//Cross product
	inline Vector3 Cross(const Vector3 &v0, const Vector3 &v1)
{
	return Vector3(
		v0.y*v1.z - v0.z*v1.y,
		v0.z*v1.x - v0.x*v1.z,
		v0.x*v1.y - v0.y*v1.x
	);
}
	//Distance between two vectors
	inline float Distance(const Vector3 &v0, const Vector3 &v1)
	{
		return sqrt(
			(v1.x - v0.x)*(v1.x - v0.x) +
			(v1.y - v0.y)*(v1.y - v0.y) +
			(v1.z - v0.z)*(v1.z - v0.z)
		);
	}
	//Angle between two vectors
	inline float Angle(const Vector3 &v0, const Vector3 &v1)
	{

		float dotProduct = v0.normalized().x*v1.normalized().x + 
							v0.normalized().y*v1.normalized().y + 
							v0.normalized().z*v1.normalized().z;
		return acos(dotProduct);
	}
	//Lerped vector between two vectors
	inline Vector3 Lerp(const Vector3 &v0, const Vector3 &v1,float t)
	{
		float d = Distance(v0, v1);
		float dx = v0.x + t * (v1.x - v0.x);
		float dy = v0.y + t * (v1.y - v0.y);
		float dz = v0.z + t * (v1.z - v0.z);
		return Vector3(dx, dy, dz);
	}
	
	