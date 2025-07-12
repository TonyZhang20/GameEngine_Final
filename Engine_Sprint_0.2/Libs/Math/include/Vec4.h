//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef ENGINE_MATH_Vect4D_H
#define ENGINE_MATH_Vect4D_H

// Includes to handle SIMD register types
#include <xmmintrin.h>
#include <smmintrin.h> 

#include "Constants.h"
#include "Vec4Proxy.h"
#include "MathExportAPI.h"

// This file assumes Framework.h is included in executable for Align16

namespace Azul
{
	// forward declare
	class Mat4;
	class Mat3;
	class Vec3;
	class Vec2;
	class Scale;
	class Trans;
	class Rot;

	// -----------------------------------------------------------
	// 
	// Vec4 
	//   True 4 element vector... 
	//     its stored in a SIMD friendly struct for cache reasons
	//                         
	//   v4  = | x  y  z  w | 
	//     
	// -----------------------------------------------------------

	class Vec4 final : public Align16
	{
	public:
		// Big 4
		MATHLIBRARY_API Vec4();
		MATHLIBRARY_API Vec4(const Vec4& inV);
		MATHLIBRARY_API Vec4& operator=(const Vec4& v);
		MATHLIBRARY_API ~Vec4();

		// Big 6
		MATHLIBRARY_API Vec4(Vec4&& v) = default;
		MATHLIBRARY_API Vec4& operator=(Vec4&& v) = default;

		// Constructors
		MATHLIBRARY_API Vec4(const float in_x, const float in_y, const float in_z, const float in_w);

		// Forces User to explicitly do the cast or constructor call with explicit
		MATHLIBRARY_API Vec4(const Vec3& v, const float w);

		// Bracket
		MATHLIBRARY_API float& operator[] (const enum x_enum);
		MATHLIBRARY_API float& operator[] (const enum y_enum);
		MATHLIBRARY_API float& operator[] (const enum z_enum);
		MATHLIBRARY_API float& operator[] (const enum w_enum);

		MATHLIBRARY_API float operator[] (const enum x_enum) const;
		MATHLIBRARY_API float operator[] (const enum y_enum) const;
		MATHLIBRARY_API float operator[] (const enum z_enum) const;
		MATHLIBRARY_API float operator[] (const enum w_enum) const;

		// Accessors - Robin's suggestion
		MATHLIBRARY_API void x(const float v);
		MATHLIBRARY_API void y(const float v);
		MATHLIBRARY_API void z(const float v);
		MATHLIBRARY_API void w(const float v);

		MATHLIBRARY_API float x() const;
		MATHLIBRARY_API float y() const;
		MATHLIBRARY_API float z() const;
		MATHLIBRARY_API float w() const;

		// add operators
		MATHLIBRARY_API Vec4 operator + (void) const;
		MATHLIBRARY_API Vec4 operator + (const Vec4& inV) const;
		MATHLIBRARY_API Vec4& operator += (const Vec4& inV);

		// sub operators
		MATHLIBRARY_API Vec4 operator - (const Vec4& inV) const;
		MATHLIBRARY_API Vec4& operator -= (const Vec4& inV);
		MATHLIBRARY_API Vec4 operator - (void) const;

		// scale operators
		MATHLIBRARY_API Vec4 operator * (const float scale) const;
		MATHLIBRARY_API friend Vec4 operator *(const float scale, const Vec4& inV);
		MATHLIBRARY_API Vec4& operator *= (const float scale);
		MATHLIBRARY_API Vec3 getVec3() const;

		// Vec4 * Mat4
		MATHLIBRARY_API Vec4 operator * (const Mat4& m) const;
		MATHLIBRARY_API Vec4& operator *= (const Mat4& m);

		// Vec4 functions
		MATHLIBRARY_API Vec4& norm(void);
		MATHLIBRARY_API Vec4 getNorm(void) const;
		MATHLIBRARY_API float dot(const Vec4& vIn) const;
		MATHLIBRARY_API Vec4Proxy len() const;

		// set
		MATHLIBRARY_API void set(const float inX, const float inY, const float inZ, const float inW);
		MATHLIBRARY_API void set(const Vec4& A);
		MATHLIBRARY_API void set(const Vec3& v, const float w);

		// comparison
		MATHLIBRARY_API bool isEqual(const Vec4& v, const float epsilon = MATH_TOLERANCE) const;
		MATHLIBRARY_API bool isZero(const float epsilon = MATH_TOLERANCE) const;

		// for printing
		MATHLIBRARY_API void Print(const char* pName) const;

	private:

		friend Mat4;
		friend Scale;
		friend Trans;
		friend Rot;
		friend Mat3;
		friend Vec3;
		friend Vec2;

		union
		{
			/*                          */
			/*   v4  = | x  y  z  w |   */
			/*                          */

			__m128	_mv;

			// anonymous struct
			struct
			{
				float _vx;
				float _vy;
				float _vz;
				float _vw;
			};
		};
	};

}

#endif

//--- End of File ---
