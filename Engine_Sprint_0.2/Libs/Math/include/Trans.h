//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef ENGINE_MATH_TRANS_4x4_H
#define ENGINE_MATH_TRANS_4x4_H

#include "Mat4.h"
#include "MathExportAPI.h"
namespace Azul
{
	class Trans final : public Mat4
	{
	public:

		// Do your magic here

		// Big 4
		MATHLIBRARY_API Trans();
		MATHLIBRARY_API Trans &operator = (const Trans &) = default;
		MATHLIBRARY_API Trans(const Trans &) = default;
		MATHLIBRARY_API ~Trans() = default;

		// Big 6
		MATHLIBRARY_API Trans(Trans &&) = default;
		MATHLIBRARY_API Trans &operator = (Trans &&) = default;

		// Constructors
		MATHLIBRARY_API Trans(const float tx, const float ty, const float tz);
		MATHLIBRARY_API explicit Trans(const Vec3 &vTrans);
		MATHLIBRARY_API explicit Trans(const enum Identity_enum);

		// Set 
		MATHLIBRARY_API void set(const float tx, const float ty, const float tz);
		MATHLIBRARY_API void set(const Vec3 &vTrans);
		MATHLIBRARY_API void set(const enum Identity_enum);

	};
}

#endif

//--- End of File ---
