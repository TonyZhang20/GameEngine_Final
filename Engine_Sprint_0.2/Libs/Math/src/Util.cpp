//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "Util.h"

 namespace Azul
{
	bool Util::isEqual(const float a, const float b, const float epsilon) 
	{
		float tmp;
		tmp = a - b;
		return ((tmp >= -epsilon) && (tmp <= epsilon));
	}

	bool Util::isNotEqual(const float a, const float b, const float epsilon)
	{
		float tmp;
		tmp = a - b;
		return ((tmp < -epsilon) || (tmp > epsilon));
	}

	bool Util::isOne(const float a, const float epsilon)
	{
		float tmp;
		tmp = a - 1.0f;
		return ((tmp >= -epsilon) && (tmp <= epsilon));
	}

	bool Util::isNonZero(const float a, const float epsilon)
	{
		return ((a < -epsilon) || (a > epsilon));
	}

	bool Util::isZero(const float a, const float epsilon)
	{
		return ((a >= -epsilon) && (a <= epsilon));
	}
}

 //--- End of File ---
