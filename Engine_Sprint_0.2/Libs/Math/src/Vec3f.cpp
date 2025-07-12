#include "MathEngine.h"

namespace Azul
{
	Vec3f::Vec3f()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}

	Vec3f::Vec3f(const Vec3f& inV)
	{
		this->x = inV.x;
		this->y = inV.y;
		this->z = inV.z;
	}

	Vec3f& Vec3f::operator=(const Vec3f& v)
	{

		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
		
		return *this;
	}

	Vec3f::Vec3f(const float x, const float y, const float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vec3f::Vec3f(const Vec3& InV)
	{
		this->x = InV[x_enum::x];
		this->y = InV[y_enum::y];
		this->z = InV[z_enum::z];
	}


	float& Vec3f::operator[](const x_enum)
	{
		return this->x;
	}

	float& Vec3f::operator[](const y_enum)
	{
		return this->y;
	}

	float& Vec3f::operator[](const z_enum)
	{
		return this->z;
	}

	float Vec3f::operator[](const x_enum) const
	{
		return this->x;
	}

	float Vec3f::operator[](const y_enum) const
	{
		return this->y;
	}
	float Vec3f::operator[](const z_enum) const
	{
		return this->z;
	}

	Vec3f Vec3f::operator+(void) const
	{
		return Vec3f(*this);
	}

	Vec3f Vec3f::operator+(const Vec3f& inV) const
	{
		Vec3f result;
		result.x = this->x + inV.x;
		result.y = this->y + inV.y;
		result.z = this->z + inV.z;
		return result;
	}

	Vec3f& Vec3f::operator+=(const Vec3f& inV)
	{
		// TODO: insert return statement here
		this->x += inV.x;
		this->y += inV.y;
		this->z += inV.z;

		return *this;
	}

	Vec3f Vec3f::operator-(const Vec3f& inV) const
	{
		Vec3f result;
		result.x = this->x - inV.x;
		result.y = this->y - inV.y;
		result.z = this->z - inV.z;
		return result;
	}

	Vec3f& Vec3f::operator-=(const Vec3f& inV)
	{
		// TODO: insert return statement here
		this->x -= inV.x;
		this->y -= inV.y;
		this->z -= inV.z;

		return *this;
	}

	Vec3f Vec3f::operator-(void) const
	{
		return Vec3f(-this->x, -this->y, -this->z);
	}

	Vec3f Vec3f::operator*(const float scale) const
	{
		Vec3f result;
		result.x = this->x * scale;
		result.y = this->y * scale;
		result.z = this->z * scale;
		return result;
	}

	Vec3f& Vec3f::operator*=(const float scale)
	{
		this->x *= scale;
		this->y *= scale;
		this->z *= scale;
		return *this;
	}

	void Vec3f::set(const float inX, const float inY, const float inZ)
	{
		this->x = inX;
		this->y = inY;
		this->z = inZ;
	}

	void Vec3f::set(const Vec3f& A)
	{
		this->x = A.x;
		this->y = A.y;
		this->z = A.z;
	}

	bool Vec3f::isEqual(const Vec3f& v, const float epsilon) const
	{
		return (std::fabs(this->x - v.x) <= epsilon) &&
			(std::fabs(this->y - v.y) <= epsilon) &&
			(std::fabs(this->z - v.z) <= epsilon);
	}

	bool Vec3f::isZero(const float epsilon) const
	{
		return (std::fabs(this->x) <= epsilon) &&
			(std::fabs(this->y) <= epsilon) &&
			(std::fabs(this->z) <= epsilon);
	}

	void Vec3f::Print(const char* pName) const
	{
		printf("(Vec3f : %s)\n", pName);
		printf("(%f , %f, %f）\n", this->x, this->y, this->z);
	}

	Vec3f operator*(const float scale, const Vec3f& inV)
	{
		Vec3f result;

		result.x = inV.x * scale;
		result.y = inV.y * scale;
		result.z = inV.z * scale;

		return result;
	}



}