//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include <d3d11.h>
#include "MathEngine.h"
#include "Mesh.h"
#include "GraphicsObject_LightTexture.h"
#include "TextureManager.h"
#include "CameraNodeManager.h"

namespace Azul
{
	// ---------------------------------------------
	//  Transfer data to the constant buffer
	//    CPU ---> GPU
	//    World, View, Projection Matrix
	// ---------------------------------------------
	GraphicsObject_LightTexture::GraphicsObject_LightTexture(Mesh *mesh,
															 ShaderObject *pShaderObj,
															 TextureObject::Name texName,
															 Vec3 &LightColor,
															 Vec3 &LightPos)
		: GraphicsObject(mesh, pShaderObj),
		pTex(TextureManager::RequireTexture(texName)),
		poLightColor(nullptr),
		poLightPos(nullptr)
	{
		assert(pTex);

		poLightColor = new Vec3(LightColor);
		poLightPos = new Vec3(LightPos);

		assert(poLightColor);
		assert(poLightPos);
	}

	GraphicsObject_LightTexture::~GraphicsObject_LightTexture()
	{
		delete poLightColor;
		delete poLightPos;
	}

	void GraphicsObject_LightTexture::SetState()
	{
		// Future - settings to directX
		// say make it wireframe or change culling mode
		this->pTex->ActivateTexture();
	}

	void GraphicsObject_LightTexture::SetDataGPU()
	{
		Camera* pCam = CameraNodeManager::GetMainCam();
		assert(pCam);

		pShaderObj->ActivateShader();
		pShaderObj->ActivateCBV();

		pShaderObj->TransferWorldViewProj(pCam, this->poWorld);
		pShaderObj->TransferLightPos(this->poLightPos);
		pShaderObj->TransferColor(this->poLightColor);

		pMesh->ActivateMesh();

	}

	void GraphicsObject_LightTexture::Draw()
	{
		pMesh->RenderIndexBuffer();
	}

	void GraphicsObject_LightTexture::RestoreState()
	{
		// Future - Undo settings to directX
	}

}

// --- End of File ---
