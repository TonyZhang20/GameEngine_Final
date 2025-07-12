#include "MovingCamera.h"

namespace Azul
{

	MovingCamera::MovingCamera(Vec3 origin, Vec3 target)
		: Camera(), _target(target), _origin(origin)
	{
	}

	void MovingCamera::updateCamera(void)
	{
		Vec3 currentPos;
		this->getPos(currentPos);

		Vec3 pos;
		Vec3 tar;
		Vec3 up;
		Vec3 upNorm;
		Vec3 forwardNorm;
		Vec3 rightNorm;

		GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);


		//Logic here
		if (movingRight)
		{
			pos = pos + speed * rightNorm;
			tar = tar + speed * rightNorm;
			up = up + speed * rightNorm;

			if (abs(currentPos.x() - _target.x()) <= 0.1f)
			{
				movingRight = false;
			}
		}
		else
		{
			pos = pos - speed * rightNorm;
			tar = tar - speed * rightNorm;
			up = up - speed * rightNorm;

			if (abs(currentPos.x() - _origin.x()) <= 0.1f)
			{
				movingRight = true;
			}
		}

		this->SetHelper(up, tar, pos);


		Camera::updateCamera();
	}

}

