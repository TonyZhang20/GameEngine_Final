//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef ENGINE_MATH_ROT_4x4_H
#define ENGINE_MATH_ROT_4x4_H

#include "Mat4.h"
#include "MathExportAPI.h"
namespace Azul
{
	class Rot final : public Mat4
	{
	public:
		// Big 4
		MATHLIBRARY_API Rot();
		MATHLIBRARY_API Rot &operator = (const Rot &) = default;
		MATHLIBRARY_API Rot(const Rot &) = default;
		MATHLIBRARY_API ~Rot() = default;

		// Big 6
		MATHLIBRARY_API Rot(Rot &&) = default;
		MATHLIBRARY_API Rot &operator = (Rot &&) = default;

		MATHLIBRARY_API explicit Rot(const enum Identity_enum);
		MATHLIBRARY_API Rot(const Mat4&);
		MATHLIBRARY_API Rot(const Rot1 type, const float angle);
		MATHLIBRARY_API Rot(const Rot3 mode, const float angle_0, const float angle_1, const float angle_2);
		MATHLIBRARY_API Rot(const Axis mode, const Vec3 &vAxis, const float angle_radians);
		MATHLIBRARY_API Rot(const Orient type, const Vec3 &dof, const Vec3 &up);

		MATHLIBRARY_API void set(const enum Identity_enum);
		MATHLIBRARY_API void set(const Rot &);
		MATHLIBRARY_API void set(const Rot1 type, const float angle);
		MATHLIBRARY_API void set(const Rot3 mode, const float angle_0, const float angle_1, const float angle_2);
		MATHLIBRARY_API void set(const Axis mode, const Vec3 &vAxis, const float angle_radians);
		MATHLIBRARY_API void set(const Orient, const Vec3 &dof, const Vec3 &up);

	private:


	};
}

#endif

//--- End of File ---
