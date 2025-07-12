#ifndef ENGINE_MATH_VECT2_H
#define ENGINE_MATH_VECT2_H

// Includes to handle SIMD register types
#include <xmmintrin.h>
#include <smmintrin.h> 

#include "Constants.h"
#include "MathExportAPI.h"
// This file assumes Framework.h is included in executable for Align16

namespace Azul
{
	// forward declare
	class Mat4;
	class Mat3;
	class Vec4;
	class Vec3;
	class Trans;
	class Scale;
	class Rot;

	// -----------------------------------------------------------
	// 
	// Vec2 
	//   True 3 element vector... 
	//     its stored in a SIMD friendly struct for cache reasons
	//     the "w" component is ignored and not set
	//                         
	//   v3  = | x  y  z  - | 
	//     
	// -----------------------------------------------------------

	class Vec2 final : public Align16
	{
	public:
		// Big 4
		MATHLIBRARY_API Vec2();
		MATHLIBRARY_API Vec2(const Vec2& inV);
		MATHLIBRARY_API Vec2& operator=(const Vec2& v);
		MATHLIBRARY_API ~Vec2();

		// Big 6
		MATHLIBRARY_API Vec2(Vec2&&) = default;
		MATHLIBRARY_API Vec2& operator = (Vec2&&) = default;

		// Constructors
		MATHLIBRARY_API Vec2(const float in_u, const float in_v);

		// Forces User to explicitly do the cast or constructor call with explicit
		MATHLIBRARY_API explicit Vec2(const Vec4& v);
		MATHLIBRARY_API Vec2& operator=(const Vec4& v);

		// Bracket
		MATHLIBRARY_API float& operator[] (const enum x_enum);
		MATHLIBRARY_API float& operator[] (const enum y_enum);

		MATHLIBRARY_API float operator[] (const enum x_enum) const;
		MATHLIBRARY_API float operator[] (const enum y_enum) const;

		// Accessors - Robin's suggestion
		MATHLIBRARY_API void u(const float v);
		MATHLIBRARY_API void v(const float v);

		MATHLIBRARY_API float u() const;
		MATHLIBRARY_API float v() const;

		// add operators
		MATHLIBRARY_API Vec2 operator + (void) const;
		MATHLIBRARY_API Vec2 operator + (const Vec2& inV) const;
		MATHLIBRARY_API Vec2& operator += (const Vec2& inV);

		// sub operators
		MATHLIBRARY_API Vec2 operator - (const Vec2& inV) const;
		MATHLIBRARY_API Vec2& operator -= (const Vec2& inV);
		MATHLIBRARY_API Vec2 operator - (void) const;

		// scale operators
		MATHLIBRARY_API Vec2 operator * (const float scale) const;
		MATHLIBRARY_API friend Vec2 operator *(const float scale, const Vec2& inV);
		MATHLIBRARY_API Vec2& operator *= (const float scale);

		// Vec2 * Mat3
		//MATHLIBRARY_API Vec2 operator* (const Mat3& m) const;
		//MATHLIBRARY_API Vec2& operator*= (const Mat3& m);

		// Vector functions
		//MATHLIBRARY_API Vec2& norm(void);
		//MATHLIBRARY_API Vec2 getNorm(void) const;
		//MATHLIBRARY_API float dot(const Vec2& vIn) const;
		//MATHLIBRARY_API Vec2 cross(const Vec2& vIn) const;
		//MATHLIBRARY_API Vec2Proxy len(void) const;
		//MATHLIBRARY_API float getAngle(const Vec2& vIn) const;

		// set
		MATHLIBRARY_API void set(const float inU, const float inV);
		MATHLIBRARY_API void set(const Vec2& A);
		MATHLIBRARY_API void set(const Vec3& A);
		MATHLIBRARY_API void set(const Vec4& A);

		// comparison
		MATHLIBRARY_API bool isEqual(const Vec2& v, const float epsilon = MATH_TOLERANCE) const;
		MATHLIBRARY_API bool isZero(const float epsilon = MATH_TOLERANCE) const;

		// for printing
		MATHLIBRARY_API void Print(const char* pName) const;

	private:

		friend Mat4;
		friend Mat3;
		friend Vec4;
		friend Vec3;
		friend Trans;
		friend Scale;
		friend Rot;

		union
		{
			/*                          */
			/*   v2  = | u  v  -  - |   */
			/*                          */

			__m128	_mv;

			// anonymous struct
			struct
			{
				float _vu;
				float _vv;
			};
		};
	};
}

#endif
