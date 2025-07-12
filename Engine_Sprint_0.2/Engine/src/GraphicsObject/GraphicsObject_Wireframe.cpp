//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include <d3d11.h>
#include "Game.h"
#include "Engine.h"
#include "MathEngine.h"
#include "Mesh.h"
#include "GraphicsObject_Wireframe.h"
#include "ShaderObject.h"
#include "CameraNodeManager.h"
#include "StateDirectXMan.h"

namespace Azul
{
	// HACK FEST --- will eventually be in managers/singleton
	extern Game* poGame;
	// ---------------------------------------------
	//  Transfer data to the constant buffer
	//    CPU ---> GPU
	//    World, View, Projection Matrix
	// ---------------------------------------------
	GraphicsObject_Wireframe::GraphicsObject_Wireframe(Mesh* _pModel, ShaderObject* _pShaderObj)
		: GraphicsObject(_pModel, _pShaderObj)
	{
		assert(pMesh);
		assert(pShaderObj);
		assert(poWorld);
	}

	void GraphicsObject_Wireframe::SetState()
	{
		poGame->mStateRasterizerWireframe.Activate();
	}

	void GraphicsObject_Wireframe::SetDataGPU()
	{
		Camera* cam = CameraNodeManager::GetMainCam();
		assert(cam);

		pShaderObj->ActivateShader();
		pShaderObj->ActivateCBV();
		pShaderObj->TransferWorldViewProj(cam, this->poWorld);
		
		pMesh->ActivateMesh();
	}

	void GraphicsObject_Wireframe::Draw()
	{
		pMesh->RenderIndexBuffer();
	}

	void GraphicsObject_Wireframe::RestoreState()
	{
		poGame->mStateRasterizerSolid.Activate();
	}
}



// ---  End of File ---
