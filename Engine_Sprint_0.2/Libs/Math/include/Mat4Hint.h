//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 


#ifdef MATH_USE_HINTS

		// Future GAM575
		enum class Hint : uint32_t
		{
			Generalize = 0x0,        // generalize 4x4 inverse  (no flags)
			Rot = 0x1,               // matrix inverse is M.T()
			Trans = 0x2,             // matrix inverse is M(-trans)
			RotTrans = 0x3,          // rot and trans  A_inv is A.T() 
			Scale = 0x4,             // matrix invers is M(1/scale)
			RotScale = 0x5,          // Rot and Scale no translate
			TransScale = 0x6,        // Trans and Scale no Translate
			Affine = 0x7             // generalize Affine

		};

#endif

//--- End of File ---
