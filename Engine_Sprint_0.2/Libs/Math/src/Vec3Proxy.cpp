//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "MathEngine.h"

namespace Azul
{
	// Add Proxy here

	Vec3Proxy::Vec3Proxy(float a, float b, float c)
	{
		this->x = a;
		this->y = b;
		this->z = c;
	}

	Vec3Proxy::operator float() const
	{
		return std::sqrt(x * x + y * y + z * z);
	}

	float Vec3Proxy::operator*(const Vec3Proxy& r) const
	{
		float a = *this;
		float b = r;
		return a * b;
	}

	bool Vec3Proxy::operator>(const Vec3Proxy& r) const
	{
		float a = *this;
		float b = r;
		return a > b;
	}

	bool Vec3Proxy::operator<(const Vec3Proxy& r) const
	{
		float a = *this;
		float b = r;
		return a < b;
	}

	bool Vec3Proxy::operator==(const Vec3Proxy& r) const
	{
		float a = *this;
		float b = r;
		return a == b;
	}

	bool Vec3Proxy::operator>=(const Vec3Proxy& r) const
	{
		float a = *this;
		float b = r;
		return a >= b;
	}

	bool Vec3Proxy::operator<=(const Vec3Proxy& r) const
	{
		float a = *this;
		float b = r;
		return a <= b;
	}

	bool Vec3Proxy::operator!=(const Vec3Proxy& r) const
	{
		float a = *this;
		float b = r;
		return a != b;
	}

}

//--- End of File ---
