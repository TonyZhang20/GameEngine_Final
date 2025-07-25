//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#ifndef ENGINE_MATH_ENUM_H
#define ENGINE_MATH_ENUM_H

//--------------------------------------------------
// Not using enum defined class for brevity in user code:
//
//      Vec3 A;
//      A[x] = 6;
//
//      Mat4 M;
//      float val = M[m5];
//
//  If enum were defined in class:
//
//      A[Vec3::x] = 6;       <------- YUCK
//      val = M[Mat4::m5];  <------- YUCK
//
//--------------------------------------------------
namespace Azul
{
	enum x_enum
	{
		x = 0,
		X = 0,
		vx = 0,
		VX = 0
	};

	enum y_enum
	{
		y = 0,
		Y = 0,
		vy = 0,
		VY = 0
	};

	enum z_enum
	{
		z = 0,
		Z = 0,
		vz = 0,
		VZ = 0
	};

	enum w_enum
	{
		w = 0,
		W = 0,
		real = 0,
		REAL = 0
	};

	enum m0_enum
	{
		m0
	};

	enum m1_enum
	{
		m1
	};

	enum m2_enum
	{
		m2
	};

	enum m3_enum
	{
		m3
	};

	enum m4_enum
	{
		m4
	};

	enum m5_enum
	{
		m5
	};

	enum m6_enum
	{
		m6
	};

	enum m7_enum
	{
		m7
	};

	enum m8_enum
	{
		m8
	};

	enum m9_enum
	{
		m9
	};

	enum m10_enum
	{
		m10
	};

	enum m11_enum
	{
		m11
	};

	enum m12_enum
	{
		m12
	};

	enum m13_enum
	{
		m13
	};

	enum m14_enum
	{
		m14
	};

	enum m15_enum
	{
		m15
	};

	enum class Rot3
	{
		XYZ,
		XZY,
		YXZ,
		YZX,
		ZXY,
		ZYX
		// future combos... here
	};

	enum class Rot1
	{
		X,
		Y,
		Z
	};

	enum class Orient
	{
		LocalToWorld,
		WorldToLocal
	};

	enum class Axis
	{
		AxisAngle,
		UnitAxisAngle
	};

	enum class Row4
	{
		i0,
		i1,
		i2,
		i3
	};

	enum class Row3
	{
		i0 = 0,
		i1 = 1,
		i2 = 2,
	};

	enum Identity_enum
	{
		Identity
	};

}

#endif

//--- End of File ---
