//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef ENGINE_MATH_MATRIX_4x4_H
#define ENGINE_MATH_MATRIX_4x4_H

#include "Vec4.h"
#include "Vec3.h"
#include "MathExportAPI.h"
// Leave this OFF for GAM475 (future for GAM575)
// #define MATH_USE_HINTS

namespace Azul
{
	struct Mat4Proxy;

	class Mat4 : public Align16
	{
	public:

		// Future
		#include "Mat4Hint.h"

	public:

		// Big 4
		MATHLIBRARY_API Mat4();
		MATHLIBRARY_API Mat4& operator = (const Mat4&);
		MATHLIBRARY_API Mat4(const Mat4&);
		MATHLIBRARY_API ~Mat4();

		// Big 6
		MATHLIBRARY_API Mat4(Mat4&&) = default;
		MATHLIBRARY_API Mat4& operator = (Mat4&&) = default;

		// Constructors
		MATHLIBRARY_API Mat4(const Vec4& tV0, const Vec4& tV1, const Vec4& tV2, const Vec4& tV3);
		MATHLIBRARY_API explicit Mat4(const enum Identity_enum);

		// Set 
		MATHLIBRARY_API void set(const Mat4& mIn);
		MATHLIBRARY_API void set(const Vec4& V0, const Vec4& V1, const Vec4& V2, const Vec4& V3);
		MATHLIBRARY_API void set(const enum Identity_enum);
		MATHLIBRARY_API void set(const Row4 type, const Vec4& V);

		// Get
		MATHLIBRARY_API Vec4 get(const Row4 type) const;

		// bracket operators	
		MATHLIBRARY_API float& operator[] (const enum m0_enum);
		MATHLIBRARY_API float& operator[] (const enum m1_enum);
		MATHLIBRARY_API float& operator[] (const enum m2_enum);
		MATHLIBRARY_API float& operator[] (const enum m3_enum);
		MATHLIBRARY_API float& operator[] (const enum m4_enum);
		MATHLIBRARY_API float& operator[] (const enum m5_enum);
		MATHLIBRARY_API float& operator[] (const enum m6_enum);
		MATHLIBRARY_API float& operator[] (const enum m7_enum);
		MATHLIBRARY_API float& operator[] (const enum m8_enum);
		MATHLIBRARY_API float& operator[] (const enum m9_enum);
		MATHLIBRARY_API float& operator[] (const enum m10_enum);
		MATHLIBRARY_API float& operator[] (const enum m11_enum);
		MATHLIBRARY_API float& operator[] (const enum m12_enum);
		MATHLIBRARY_API float& operator[] (const enum m13_enum);
		MATHLIBRARY_API float& operator[] (const enum m14_enum);
		MATHLIBRARY_API float& operator[] (const enum m15_enum);

		MATHLIBRARY_API float operator[] (const enum m0_enum) const;
		MATHLIBRARY_API float operator[] (const enum m1_enum) const;
		MATHLIBRARY_API float operator[] (const enum m2_enum) const;
		MATHLIBRARY_API float operator[] (const enum m3_enum) const;
		MATHLIBRARY_API float operator[] (const enum m4_enum) const;
		MATHLIBRARY_API float operator[] (const enum m5_enum) const;
		MATHLIBRARY_API float operator[] (const enum m6_enum) const;
		MATHLIBRARY_API float operator[] (const enum m7_enum) const;
		MATHLIBRARY_API float operator[] (const enum m8_enum) const;
		MATHLIBRARY_API float operator[] (const enum m9_enum) const;
		MATHLIBRARY_API float operator[] (const enum m10_enum) const;
		MATHLIBRARY_API float operator[] (const enum m11_enum) const;
		MATHLIBRARY_API float operator[] (const enum m12_enum) const;
		MATHLIBRARY_API float operator[] (const enum m13_enum) const;
		MATHLIBRARY_API float operator[] (const enum m14_enum) const;
		MATHLIBRARY_API float operator[] (const enum m15_enum) const;

		// Accessor	
		MATHLIBRARY_API void m0(const float v);
		MATHLIBRARY_API void m1(const float v);
		MATHLIBRARY_API void m2(const float v);
		MATHLIBRARY_API void m3(const float v);
		MATHLIBRARY_API void m4(const float v);
		MATHLIBRARY_API void m5(const float v);
		MATHLIBRARY_API void m6(const float v);
		MATHLIBRARY_API void m7(const float v);
		MATHLIBRARY_API void m8(const float v);
		MATHLIBRARY_API void m9(const float v);
		MATHLIBRARY_API void m10(const float v);
		MATHLIBRARY_API void m11(const float v);
		MATHLIBRARY_API void m12(const float v);
		MATHLIBRARY_API void m13(const float v);
		MATHLIBRARY_API void m14(const float v);
		MATHLIBRARY_API void m15(const float v);

		MATHLIBRARY_API float m0() const;
		MATHLIBRARY_API float m1() const;
		MATHLIBRARY_API float m2() const;
		MATHLIBRARY_API float m3() const;
		MATHLIBRARY_API float m4() const;
		MATHLIBRARY_API float m5() const;
		MATHLIBRARY_API float m6() const;
		MATHLIBRARY_API float m7() const;
		MATHLIBRARY_API float m8() const;
		MATHLIBRARY_API float m9() const;
		MATHLIBRARY_API float m10() const;
		MATHLIBRARY_API float m11() const;
		MATHLIBRARY_API float m12() const;
		MATHLIBRARY_API float m13() const;
		MATHLIBRARY_API float m14() const;
		MATHLIBRARY_API float m15() const;

		// Determinant
		MATHLIBRARY_API float det() const;

		// Transpose
		MATHLIBRARY_API Mat4& T(void);
		MATHLIBRARY_API Mat4 getT(void) const;

		// Inverse
		MATHLIBRARY_API Mat4 getInv(void) const;
		MATHLIBRARY_API Mat4& inv(void);

		// Comparison
		MATHLIBRARY_API bool isEqual(const Mat4& A, const float epsilon = MATH_TOLERANCE) const;
		MATHLIBRARY_API bool isIdentity(const float epsilon = MATH_TOLERANCE) const;
		MATHLIBRARY_API bool isRotation(const float epsilon = MATH_TOLERANCE) const;

		// Add operators
		MATHLIBRARY_API Mat4 operator + (void) const;
		MATHLIBRARY_API Mat4 operator + (const Mat4& A) const;
		MATHLIBRARY_API Mat4& operator += (const Mat4& A);

		// Sub operators
		MATHLIBRARY_API Mat4 operator - (void) const;
		MATHLIBRARY_API Mat4 operator - (const Mat4& A) const;
		MATHLIBRARY_API Mat4& operator -= (const Mat4& A);

		// Scale operators
		MATHLIBRARY_API Mat4 operator * (const float s) const;
		MATHLIBRARY_API friend Mat4 operator *(const float scale, const Mat4& A);
		MATHLIBRARY_API Mat4& operator *= (const float scale);

		// Multiply
		MATHLIBRARY_API Mat4 operator * (const Mat4& A) const;
		MATHLIBRARY_API Mat4& operator *= (const Mat4& A);

		// For printing
		MATHLIBRARY_API void Print(const char* pName) const;

	protected:

		friend Mat3;
		friend Vec3;
		friend Vec4;
		friend Mat4Proxy;
		friend Rot;

		union
		{
			/*     | m0  m1  m2   m3  | */
			/* m = | m4  m5  m6   m7  | */
			/*     | m8  m9  m10  m11 | */
			/*     | m12 m13 m14  m15 | */

			struct
			{
				Vec4 _rows[4];
			};


			struct
			{
				Vec4 _v0;
				Vec4 _v1;
				Vec4 _v2;
				Vec4 _v3;
			};

			struct
			{
				float _m0;
				float _m1;
				float _m2;
				float _m3;
				float _m4;
				float _m5;
				float _m6;
				float _m7;
				float _m8;
				float _m9;
				float _m10;
				float _m11;
				float _m12;
				float _m13;
				float _m14;
				union
				{
					float _m15;
					unsigned int _u_m15;
				};
			};
		};
	};
}

#endif

//--- End of File ---
