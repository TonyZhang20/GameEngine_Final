//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef GAME_ROTATE_OBJECT_H
#define GAME_ROTATE_OBJECT_H

#include "MathEngine.h"
#include "PCSNode.h"
#include "GameObject.h"
#include "GraphicsObject.h"

namespace Azul
{

	class GameObject_RotateAround : public GameObject
	{
	public:
		GameObject_RotateAround();
		GameObject_RotateAround(GraphicsObject* poGraphicsObject);

		GameObject_RotateAround(const GameObject_RotateAround&) = delete;
		GameObject_RotateAround& operator = (const GameObject_RotateAround&) = delete;
		~GameObject_RotateAround();

		void SetTarget(GameObject* target);
		void Update(float t) override;
		void Draw() override;
		void SetDir(Rot1 rot);
		void SetLightColor(Vec4 originColor, Vec4 targetColor);

	protected:
		GameObject* target;
		Rot1 dir = Rot1::Y;
		float angle = 0;
		
		//For Demo
		Vec3 orgin;
		Vec3 targetC;

	public:
		bool rotate = false;
		bool colorChange = false;

		float colorLerpT = 0.0f;
		float colorChangeSpeed = 0.5f;
	};

}


#endif


// --- End of File ---
