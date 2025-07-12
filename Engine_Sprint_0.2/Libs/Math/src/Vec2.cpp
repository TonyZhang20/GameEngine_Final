#include "MathEngine.h"

namespace Azul
{
	Vec2::Vec2()
	{
		this->_vu = 0;
		this->_vv = 0;
	}

	Vec2::Vec2(const Vec2& inV)
	{
		this->_mv = inV._mv;
	}

	Vec2& Vec2::operator=(const Vec2& v)
	{
		if (this != &v)
		{
			this->_mv = v._mv;
		}
		return *this;
	}

	Vec2::~Vec2()
	{
	}

	Vec2::Vec2(const float in_u, const float in_v)
	{
		_mv = _mm_set_ps(0.0f, 0.0f, in_v, in_u);
	}

	Vec2::Vec2(const Vec4& v)
	{
		this->_vu = v._vx;
		this->_vv = v._vy;
	}

	Vec2& Vec2::operator=(const Vec4& v)
	{
		// TODO: insert return statement here
		this->_mv = _mm_set_ps(0.0f, 0.0f, v._vy, v._vx);
		return *this;
	}

	float& Vec2::operator[](const x_enum)
	{
		return this->_vu;
	}

	float& Vec2::operator[](const y_enum)
	{
		return this->_vv;
	}

	float Vec2::operator[](const x_enum) const
	{
		return this->_vu;
	}

	float Vec2::operator[](const y_enum) const
	{
		return this->_vv;
	}

	void Vec2::u(const float v)
	{
		this->_vu = v;
	}

	void Vec2::v(const float v)
	{
		this->_vv = v;
	}

	float Vec2::u() const
	{
		return this->_vu;
	}

	float Vec2::v() const
	{
		return this->_vv;
	}

	Vec2 Vec2::operator+(void) const
	{
		return Vec2(*this);
	}

	Vec2 Vec2::operator+(const Vec2& inV) const
	{
		Vec2 result;
		result._mv = _mm_add_ps(this->_mv, inV._mv);

		return result;
	}

	Vec2& Vec2::operator+=(const Vec2& inV)
	{
		// TODO: insert return statement here
		this->_mv = _mm_add_ps(this->_mv, inV._mv);
		return *this;
	}

	Vec2 Vec2::operator-(const Vec2& inV) const
	{
		Vec2 result;
		result._mv = _mm_sub_ps(this->_mv, inV._mv);

		return result;
	}

	Vec2& Vec2::operator-=(const Vec2& inV)
	{
		// TODO: insert return statement here
		this->_mv = _mm_sub_ps(this->_mv, inV._mv);
		return *this;
	}

	Vec2 Vec2::operator-(void) const
	{
		return Vec2(-this->_vu, -this->_vv);
	}

	Vec2 Vec2::operator*(const float scale) const
	{
		Vec2 result;
		__m128 scaleVec = _mm_set1_ps(scale);
		result._mv = _mm_mul_ps(this->_mv, scaleVec);

		return result;
	}

	Vec2& Vec2::operator*=(const float scale)
	{
		__m128 scaleVec = _mm_set1_ps(scale);
		this->_mv = _mm_mul_ps(this->_mv, scaleVec);
		return *this;
	}

	void Vec2::set(const float inU, const float inV)
	{
		this->_mv = _mm_set_ps(0, 0, inV, inU);
	}

	void Vec2::set(const Vec2& A)
	{
		this->_mv = _mm_set_ps(0, 0, A._vv, A._vu);
	}

	void Vec2::set(const Vec3& A)
	{
		this->_mv = _mm_set_ps(0, A._vz, A._vy, A._vx);
	}

	void Vec2::set(const Vec4& A)
	{
		this->_mv = _mm_set_ps(0, 0, A._vy, A._vx);
	}

	bool Vec2::isEqual(const Vec2& v, const float epsilon) const
	{
		return (std::fabs(this->_vu - v._vu) <= epsilon) &&
			(std::fabs(this->_vv - v._vv) <= epsilon);
	}

	bool Vec2::isZero(const float epsilon) const
	{
		return (std::fabs(this->_vu) <= epsilon) &&
			(std::fabs(this->_vv) <= epsilon);
	}

	void Vec2::Print(const char* pName) const
	{
		printf("(Vec2 : %s)\n", pName);
		printf("(%f , %f）\n", this->_vu, this->_vv);
	}

	Vec2 operator*(const float scale, const Vec2& inV)
	{
		Vec2 result;
		__m128 scaleVec = _mm_set1_ps(scale);
		result._mv = _mm_mul_ps(inV._mv, scaleVec);

		return result;
	}



}