//--------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//--------------------------------------------------------------

#include "CameraUtility.h"
#include "Camera.h"

namespace Azul
{
	CameraUtility *CameraUtility::posInstance = nullptr;
	bool CameraUtility::Ready = false;

	static Vec3 obj(0.0f, 0.0f, 0.0f);


	CameraUtility *CameraUtility::privGetInstance()
	{
		if (CameraUtility::posInstance == nullptr)
		{
			CameraUtility::posInstance = new CameraUtility();
		}

		return posInstance;
	}

	CameraUtility::~CameraUtility()
	{
		CameraUtility::Ready = false;
	}


	void CameraUtility::Destroy()
	{
		delete CameraUtility::posInstance;
	}

	void CameraUtility::RememberOrginSet(Camera* pCam)
	{
		CameraUtility* pUtil = CameraUtility::privGetInstance();

		pCam->updateCamera();
		pCam->GetHelper(pUtil->Orig_up,
			pUtil->Orig_tar,
			pUtil->Orig_pos,
			pUtil->Orig_upNorm,
			pUtil->Orig_forwardNorm,
			pUtil->Orig_rightNorm);
	}

	void CameraUtility::Create(Camera *pCam)
	{
		CameraUtility *pUtil = CameraUtility::privGetInstance();
		assert(pUtil);
		assert(pCam);

		pCam->updateCamera();
		pCam->GetHelper(pUtil->Orig_up, 
						pUtil->Orig_tar,
						pUtil->Orig_pos,
						pUtil->Orig_upNorm, 
						pUtil->Orig_forwardNorm, 
						pUtil->Orig_rightNorm);

		CameraUtility::Ready = true;
	}


	void CameraUtility::OrbitCamera(Camera *pCam)
	{
		CameraUtility *pUtil = CameraUtility::privGetInstance();
		assert(pUtil);
		assert(pCam);
		assert(CameraUtility::Ready);

		// OK, now 3 points... pos, tar, up
		//     now 3 normals... upNorm, forwardNorm, rightNorm
		//     tar = obj;
		pUtil->privUpdateHelper(pCam);

		if ((GetKeyState('S') & 0x8000))
		{
			// Reset	
			obj.set(0, 0, 0);
			pCam->SetHelper(pUtil->Orig_up, pUtil->Orig_tar, pUtil->Orig_pos);
		}

		if ((GetKeyState('W') & 0x8000))
		{
			Vec3 newObj(2, 0, 0);
			Vec3 pos;
			Vec3 tar;
			Vec3 up;
			Vec3 upNorm;
			Vec3 forwardNorm;
			Vec3 rightNorm;

			pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);

			// OK, now 3 points... pos, tar, up
			//     now 3 normals... upNorm, forwardNorm, rightNorm

			Vec3 delta = newObj - obj;

			up += delta;
			tar += delta;
			pos += delta;

			obj = newObj;

			pCam->SetHelper(up, tar, pos);
		}

		if ((GetKeyState('E') & 0x8000))
		{
			Vec3 newObj(-2, 0, 0);
			Vec3 pos;
			Vec3 tar;
			Vec3 up;
			Vec3 upNorm;
			Vec3 forwardNorm;
			Vec3 rightNorm;

			pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);

			// OK, now 3 points... pos, tar, up
			//     now 3 normals... upNorm, forwardNorm, rightNorm

			Vec3 delta = newObj - obj;

			up += delta;
			tar += delta;
			pos += delta;

			obj = newObj;

			pCam->SetHelper(up, tar, pos);
		}

		if ((GetKeyState('D') & 0x8000))
		{
			Vec3 newObj(0, 0, 0);
			Vec3 pos;
			Vec3 tar;
			Vec3 up;
			Vec3 upNorm;
			Vec3 forwardNorm;
			Vec3 rightNorm;

			pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);

			// OK, now 3 points... pos, tar, up
			//     now 3 normals... upNorm, forwardNorm, rightNorm
			Vec3 delta = newObj - obj;

			up += delta;
			tar += delta;
			pos += delta;

			obj = newObj;

			pCam->SetHelper(up, tar, pos);
		}

		if ((GetKeyState('I') & 0x8000))
		{
			pUtil->pos = pUtil->pos + 0.03f * pUtil->forwardNorm;
			//tar = tar + 0.03f * forwardNorm;
			pUtil->up = pUtil->up + 0.03f * pUtil->forwardNorm;

			pUtil->tar = pUtil->tar + 0.03f * pUtil->forwardNorm;

			pCam->SetHelper(pUtil->up, pUtil->tar, pUtil->pos);
		}

		if ((GetKeyState('K') & 0x8000))
		{
			pUtil->pos = pUtil->pos - 0.03f * pUtil->forwardNorm;

			pUtil->up = pUtil->up - 0.03f * pUtil->forwardNorm;

			pUtil->tar = pUtil->tar - 0.03f * pUtil->forwardNorm;

			pCam->SetHelper(pUtil->up, pUtil->tar, pUtil->pos);
		}

		if ((GetKeyState('J') & 0x8000))
		{
			pUtil->pos = pUtil->pos - 0.03f * pUtil->rightNorm;
			pUtil->tar = pUtil->tar - 0.03f * pUtil->rightNorm;
			pUtil->up = pUtil->up - 0.03f * pUtil->rightNorm;

			pCam->SetHelper(pUtil->up, pUtil->tar, pUtil->pos);
		}

		if ((GetKeyState('L') & 0x8000))
		{
			pUtil->pos = pUtil->pos + 0.03f * pUtil->rightNorm;
			pUtil->tar = pUtil->tar + 0.03f * pUtil->rightNorm;
			pUtil->up = pUtil->up + 0.03f * pUtil->rightNorm;

			pCam->SetHelper(pUtil->up, pUtil->tar, pUtil->pos);
		}

		if ((GetKeyState(VK_RIGHT) & 0x8000))
		{
			Trans TransA(pUtil->tar);
			Trans NegTrans(-pUtil->tar);

			Rot RotA;
			RotA.set(Axis::AxisAngle, pUtil->upNorm, +0.03f);

			Mat4 M = NegTrans * RotA * TransA;

			pUtil->up = Vec4(pUtil->up, 1.0f) * M;
			pUtil->pos = Vec4(pUtil->pos, 1.0f) * M;
			pUtil->tar = Vec4(pUtil->tar, 1.0f) * M;

			pCam->SetHelper(pUtil->up, pUtil->tar, pUtil->pos);
		}

		if ((GetKeyState(VK_LEFT) & 0x8000))
		{
			Trans TransA(pUtil->tar);
			Trans NegTrans(-pUtil->tar);

			Rot RotA;
			RotA.set(Axis::AxisAngle, pUtil->upNorm, -0.03f);

			Mat4 M = NegTrans * RotA * TransA;

			pUtil->up = Vec4(pUtil->up, 1.0f) * M;
			pUtil->pos = Vec4(pUtil->pos, 1.0f) * M;
			pUtil->tar = Vec4(pUtil->tar, 1.0f) * M;

			pCam->SetHelper(pUtil->up, pUtil->tar, pUtil->pos);
		}

		if ((GetKeyState(VK_DOWN) & 0x8000))
		{
			Trans TransA(pUtil->tar);
			Trans NegTrans(-pUtil->tar);

			Rot RotA;
			RotA.set(Axis::AxisAngle, pUtil->rightNorm, 0.03f);

			Mat4 M = NegTrans * RotA * TransA;

			pUtil->up = Vec4(pUtil->up, 1.0f) * M;
			pUtil->pos = Vec4(pUtil->pos, 1.0f) * M;
			pUtil->tar = Vec4(pUtil->tar, 1.0f) * M;

			pCam->SetHelper(pUtil->up, pUtil->tar, pUtil->pos);
		}

		if ((GetKeyState(VK_UP) & 0x8000))
		{
			Trans TransA(pUtil->tar);
			Trans NegTrans(-pUtil->tar);

			Rot RotA;
			RotA.set(Axis::AxisAngle, pUtil->rightNorm, -0.03f);

			Mat4 M = NegTrans * RotA * TransA;

			pUtil->up = Vec4(pUtil->up, 1.0f) * M;
			pUtil->pos = Vec4(pUtil->pos, 1.0f) * M;
			pUtil->tar = Vec4(pUtil->tar, 1.0f) * M;

			pCam->SetHelper(pUtil->up, pUtil->tar, pUtil->pos);
		}

	}

	void CameraUtility::privUpdateHelper(Camera *pCam)
	{
		assert(pCam);
		pCam->GetHelper(up, 
						tar,
						pos,
						upNorm,
						forwardNorm,
						rightNorm);

	}

}

// --- End of File ---
