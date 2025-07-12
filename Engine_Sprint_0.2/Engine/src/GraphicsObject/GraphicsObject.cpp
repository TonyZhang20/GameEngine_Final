//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "GraphicsObject.h"
#include "MathEngine.h"
#include "Mesh.h"

namespace Azul
{
	GraphicsObject::GraphicsObject()
	{
		this->poWorld = new Mat4(Identity);
	}

	GraphicsObject::GraphicsObject(Mesh* model, ShaderObject* _pShaderObj)
		: pMesh(model),
		pShaderObj(_pShaderObj)
	{
		this->poWorld = new Mat4(Identity);

		assert(model);
		assert(_pShaderObj);
	}

	GraphicsObject::~GraphicsObject()
	{
		delete this->poWorld;
	}

	void GraphicsObject::Render()
	{
		this->SetState();
		this->SetDataGPU();
		this->Draw();
		this->RestoreState();
	}

	Mesh* GraphicsObject::GetModel() const
	{
		return this->pMesh;
	}

	Mat4& GraphicsObject::GetWorld()
	{
		return *this->poWorld;
	}

	void GraphicsObject::SetWorld(Mat4& _world)
	{
		*this->poWorld = _world;
	}
}



// --- End of File ---
