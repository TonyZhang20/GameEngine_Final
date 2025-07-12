//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Engine.h"
#include "Mesh.h"
#include "StringThis.h"
#include "StateDirectXMan.h"
#include "ShaderMappings.h"


namespace Azul
{
	Mesh::Mesh(unsigned int _numVerts, unsigned int _numIndices)
		:
		numVerts{ _numVerts },
		numIndices{ _numIndices }
	{

	}

	Mesh::Mesh()
		:
		numVerts{ 0 },
		numIndices{ 0 }
	{

	}

	Mesh::~Mesh()
	{

	}

	void Mesh::Wash()
	{

	}

	bool Mesh::Compare(DLink* pTarget)
	{
		// This is used in ManBase.Find() 
		assert(pTarget != nullptr);

		Mesh* pDataB = (Mesh*)pTarget;

		bool status = false;

		if (this->name == pDataB->name)
		{
			status = true;
		}

		return status;
	}

	void Mesh::SetName(Mesh::Name _name)
	{
		this->name = _name;
	}

	void Mesh::Initialize(unsigned int numVerts, unsigned int numTriangles)
	{
		this->numVerts = numVerts;
		this->numIndices = numTriangles;
	}

	char* Mesh::GetName()
	{
		// todo - Hack understand why is this needed for print and fix...
		static char pTmp[128];
		strcpy_s(pTmp, 128, StringMe(this->name));
		return pTmp;
	}
}


// --- End of File ---
