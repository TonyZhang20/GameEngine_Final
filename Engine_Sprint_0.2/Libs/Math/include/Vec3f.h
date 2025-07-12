#ifndef ENGINE_MATH_VECT3F_H
#define ENGINE_MATH_VECT3F_H
#include <xmmintrin.h>
#include <smmintrin.h> 

#include "Enum.h"
#include "Constants.h"
#include "MathExportAPI.h"
namespace Azul
{
	class Vec3;

	class Vec3f final
	{
	public:
		MATHLIBRARY_API Vec3f();
		MATHLIBRARY_API Vec3f(const Vec3f&);
		MATHLIBRARY_API Vec3f& operator = (const Vec3f&);
		MATHLIBRARY_API ~Vec3f() = default;

		MATHLIBRARY_API Vec3f(const float x, const float y, const float z);
		MATHLIBRARY_API Vec3f(const Vec3& InV);

		MATHLIBRARY_API float& operator[] (const enum x_enum);
		MATHLIBRARY_API float& operator[] (const enum y_enum);
		MATHLIBRARY_API float& operator[] (const enum z_enum);

		MATHLIBRARY_API float operator[] (const enum x_enum) const;
		MATHLIBRARY_API float operator[] (const enum y_enum) const;
		MATHLIBRARY_API float operator[] (const enum z_enum) const;
		// add operators
		MATHLIBRARY_API Vec3f operator + (void) const;
		MATHLIBRARY_API Vec3f operator + (const Vec3f& inV) const;
		MATHLIBRARY_API Vec3f& operator += (const Vec3f& inV);

		// sub operators
		MATHLIBRARY_API Vec3f operator - (const Vec3f& inV) const;
		MATHLIBRARY_API Vec3f& operator -= (const Vec3f& inV);
		MATHLIBRARY_API Vec3f operator - (void) const;

		// scale operators
		MATHLIBRARY_API Vec3f operator * (const float scale) const;
		MATHLIBRARY_API friend Vec3f operator *(const float scale, const Vec3f& inV);
		MATHLIBRARY_API Vec3f& operator *= (const float scale);

		MATHLIBRARY_API void set(const float inX, const float inY, const float inZ);
		MATHLIBRARY_API void set(const Vec3f& A);
		// comparison
		MATHLIBRARY_API bool isEqual(const Vec3f& v, const float epsilon = MATH_TOLERANCE) const;
		MATHLIBRARY_API bool isZero(const float epsilon = MATH_TOLERANCE) const;

		// for printing
		MATHLIBRARY_API void Print(const char* pName) const;


	private:
		friend Vec3;

		float x;
		float y;
		float z;
	};
}


#endif