//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef MESH_MAN_H
#define MESH_MAN_H 

#include "ManBase.h"
#include "MeshNode.h"
#include "Mesh.h"

namespace Azul
{
	class MeshNodeManager : public ManBase
	{
		//----------------------------------------------------------------------
		// Static Methods
		//----------------------------------------------------------------------
	public:
		static void Create(int reserveNum = 0, int reserveGrow = 1);
		static void Destroy();

		static MeshNode* Add(Mesh::Name name, Mesh* pMesh);
		static MeshNode* Find(Mesh::Name name);

		static void Remove(MeshNode* pNode);
		static void Dump();

		//----------------------------------------------------------------------
		// Private methods
		//----------------------------------------------------------------------
	private:
		static MeshNodeManager* privGetInstance();

		~MeshNodeManager();
		MeshNodeManager(int reserveNum, int reserveGrow);

		//----------------------------------------------------------------------
		// Override Abstract methods
		//----------------------------------------------------------------------
	protected:
		DLink* derivedCreateNode() override;

		//----------------------------------------------------------------------
		// Data: unique data for this manager 
		//----------------------------------------------------------------------
	private:
		MeshNode* poNodeCompare;
		static MeshNodeManager* posInstance;

	};
}


#endif

// --- End of File ---
