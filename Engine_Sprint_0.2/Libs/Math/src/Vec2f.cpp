#include "MathEngine.h"

namespace Azul
{
	Vec2f::Vec2f()
	{
		this->u = 0;
		this->v = 0;
	}

	Vec2f::Vec2f(const Vec2f& inV)
	{
		this->u = inV.u;
		this->v = inV.v;
	}

	Vec2f& Vec2f::operator=(const Vec2f& V)
	{

		this->u = V.u;
		this->v = V.v;
		
		return *this;
	}

	Vec2f::Vec2f(const float in_u, const float in_v)
	{
		this->u = in_u;
		this->v = in_v;
	}

	Vec2f::Vec2f(const Vec2& InV)
	{
		this->u = InV[x];
		this->v = InV[y];
	}

	float& Vec2f::operator[](const x_enum)
	{
		return this->u;
	}

	float& Vec2f::operator[](const y_enum)
	{
		return this->v;
	}

	float Vec2f::operator[](const x_enum) const
	{
		return this->u;
	}

	float Vec2f::operator[](const y_enum) const
	{
		return this->v;
	}

	Vec2f Vec2f::operator+(void) const
	{
		return Vec2f(*this);
	}

	Vec2f Vec2f::operator+(const Vec2f& inV) const
	{
		Vec2f result;
		result.u = this->u + inV.u;
		result.v = this->v + inV.v;
		return result;
	}

	Vec2f& Vec2f::operator+=(const Vec2f& inV)
	{
		// TODO: insert return statement here
		this->u += inV.u;
		this->v += inV.v;

		return *this;
	}

	Vec2f Vec2f::operator-(const Vec2f& inV) const
	{
		Vec2f result;
		result.u = this->u - inV.u;
		result.v = this->v - inV.v;
		return result;
	}

	Vec2f& Vec2f::operator-=(const Vec2f& inV)
	{
		// TODO: insert return statement here
		this->u -= inV.u;
		this->v -= inV.v;

		return *this;
	}

	Vec2f Vec2f::operator-(void) const
	{
		return Vec2f(-this->u, -this->v);
	}

	Vec2f Vec2f::operator*(const float scale) const
	{
		Vec2f result;
		result.u = this->u * scale;
		result.v = this->v * scale;
		return result;
	}

	Vec2f& Vec2f::operator*=(const float scale)
	{
		this->u *= scale;
		this->v *= scale;

		return *this;
	}

	void Vec2f::set(const float inU, const float inV)
	{
		this->u = inU;
		this->v = inV;
	}

	void Vec2f::set(const Vec2f& A)
	{
		this->u = A.u;
		this->v = A.v;
	}

	bool Vec2f::isEqual(const Vec2f& V, const float epsilon) const
	{
		return (std::fabs(this->u - V.u) <= epsilon) &&
			(std::fabs(this->v - V.v) <= epsilon);
	}

	bool Vec2f::isZero(const float epsilon) const
	{
		return (std::fabs(this->u) <= epsilon) &&
			(std::fabs(this->v) <= epsilon);
	}

	void Vec2f::Print(const char* pName) const
	{
		printf("(Vec2f : %s)\n", pName);
		printf("(%f , %f）\n", this->u, this->v);
	}

	Vec2f operator*(const float scale, const Vec2f& inV)
	{
		Vec2f result;

		result.u = inV.u * scale;
		result.v = inV.v * scale;

		return result;
	}



}