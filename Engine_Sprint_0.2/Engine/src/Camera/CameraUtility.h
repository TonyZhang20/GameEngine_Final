//--------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//--------------------------------------------------------------

#ifndef CAMERA_UTILITY_H
#define CAMERA_UTILITY_H

#include "MathEngine.h"

namespace Azul
{
	class Camera;  // foreword declare

	class CameraUtility
	{

	public:
		// Default constructor
		CameraUtility() = default;
		CameraUtility(const CameraUtility &) = delete;
		CameraUtility &operator = (const CameraUtility &) = delete;
		~CameraUtility();

		static void Create(Camera *pCam);
		static void Destroy();
		static void RememberOrginSet(Camera *pCam);

		static void OrbitCamera(Camera *pCam);

	private:		
		void privUpdateHelper(Camera *pCam);
		static CameraUtility *privGetInstance();
		static CameraUtility *posInstance;

		static bool Ready;

		Vec3 pos;
		Vec3 tar;
		Vec3 up;
		Vec3 upNorm;
		Vec3 forwardNorm;
		Vec3 rightNorm;

		Vec3 Orig_pos;
		Vec3 Orig_tar;
		Vec3 Orig_up;
		Vec3 Orig_upNorm;
		Vec3 Orig_forwardNorm;
		Vec3 Orig_rightNorm;
	};
}

#endif

// --- End of File ---