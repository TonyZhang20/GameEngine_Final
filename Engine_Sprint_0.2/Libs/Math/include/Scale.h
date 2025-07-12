//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef ENGINE_MATH_SCALE_4x4_H
#define ENGINE_MATH_SCALE_4x4_H

#include "Mat4.h"
#include "MathExportAPI.h"
namespace Azul
{
	class Scale final : public Mat4
	{
	public:
		// Big 4
		MATHLIBRARY_API Scale();
		MATHLIBRARY_API Scale &operator = (const Scale &) = default;
		MATHLIBRARY_API Scale(const Scale &) = default;
		MATHLIBRARY_API ~Scale() = default;

		// Big 6
		MATHLIBRARY_API Scale(Scale &&) = default;
		MATHLIBRARY_API Scale &operator = (Scale &&) = default;

		// Constructors
		MATHLIBRARY_API Scale(const float sx, const float sy, const float sz);
		MATHLIBRARY_API explicit Scale(const Vec3 &vScale);
		MATHLIBRARY_API explicit Scale(const enum Identity_enum);

		// Set 
		MATHLIBRARY_API void set(const float sx, const float sy, const float sz);
		MATHLIBRARY_API void set(const Vec3 &vScale);
		MATHLIBRARY_API void set(const enum Identity_enum);

	};
}

#endif

//--- End of File ---
