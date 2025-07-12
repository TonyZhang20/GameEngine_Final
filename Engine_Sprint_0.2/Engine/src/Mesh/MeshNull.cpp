#include "MeshNull.h"
#include "MeshNodeManager.h"

namespace Azul
{
	MeshNull::MeshNull()
		: Mesh(0, 0)
	{
		this->name = Name::NULL_MESH;
	}

	MeshNull::~MeshNull()
	{
		// remove anything dynamic here
	}
	void MeshNull::ActivateMesh()
	{

	}
	void MeshNull::RenderIndexBuffer()
	{

	}
}



// --- End of File ---
