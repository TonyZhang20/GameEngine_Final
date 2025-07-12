#ifndef ENGINE_MATH_VECT2F_H
#define ENGINE_MATH_VECT2F_H
#include <xmmintrin.h>
#include <smmintrin.h> 

#include "Enum.h"
#include "Constants.h"
#include "MathExportAPI.h"

namespace Azul
{
	class Vec2;

	class Vec2f final
	{
	public:
		MATHLIBRARY_API Vec2f();
		MATHLIBRARY_API Vec2f(const Vec2f&);
		MATHLIBRARY_API Vec2f& operator = (const Vec2f&);
		MATHLIBRARY_API ~Vec2f() = default;

		MATHLIBRARY_API Vec2f(const float _u, const float _v);
		MATHLIBRARY_API Vec2f(const Vec2& InV);

		MATHLIBRARY_API float& operator[] (const enum x_enum);
		MATHLIBRARY_API float& operator[] (const enum y_enum);

		MATHLIBRARY_API float operator[] (const enum x_enum) const;
		MATHLIBRARY_API float operator[] (const enum y_enum) const;

		// add operators
		MATHLIBRARY_API Vec2f operator + (void) const;
		MATHLIBRARY_API Vec2f operator + (const Vec2f& inV) const;
		MATHLIBRARY_API Vec2f& operator += (const Vec2f& inV);

		// sub operators
		MATHLIBRARY_API Vec2f operator - (const Vec2f& inV) const;
		MATHLIBRARY_API Vec2f& operator -= (const Vec2f& inV);
		MATHLIBRARY_API Vec2f operator - (void) const;

		// scale operators
		MATHLIBRARY_API Vec2f operator * (const float scale) const;
		MATHLIBRARY_API friend Vec2f operator *(const float scale, const Vec2f& inV);
		MATHLIBRARY_API Vec2f& operator *= (const float scale);

		MATHLIBRARY_API void set(const float inU, const float inV);
		MATHLIBRARY_API void set(const Vec2f& A);
		// comparison
		MATHLIBRARY_API bool isEqual(const Vec2f& v, const float epsilon = MATH_TOLERANCE) const;
		MATHLIBRARY_API bool isZero(const float epsilon = MATH_TOLERANCE) const;

		// for printing
		MATHLIBRARY_API void Print(const char* pName) const;


	private:
		friend Vec2;

		float u;
		float v;

	};
}


#endif