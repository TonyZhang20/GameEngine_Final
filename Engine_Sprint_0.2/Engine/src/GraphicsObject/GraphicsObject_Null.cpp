//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "GraphicsObject_Null.h"
#include "MeshNodeManager.h"
#include "MeshNull.h"
#include "Mesh.h"

#include "ShaderObject.h"
#include "ShaderObject_Null.h"
#include "ShaderObjectNodeManager.h"

namespace Azul
{
	GraphicsObject_Null::GraphicsObject_Null()
	{
		this->pMesh = new MeshNull();
		this->pShaderObj = new ShaderObject_Null();

		ShaderObjectNodeManager::Add(this->pShaderObj);
		MeshNodeManager::Add(Mesh::Name::NULL_MESH, this->pMesh);
	}

	GraphicsObject_Null::~GraphicsObject_Null()
	{

	}

	void GraphicsObject_Null::SetState()
	{

	}

	void GraphicsObject_Null::SetDataGPU()
	{

	}

	void GraphicsObject_Null::Draw()
	{

	}

	void GraphicsObject_Null::RestoreState()
	{

	}

}



// ---  End of File ---
