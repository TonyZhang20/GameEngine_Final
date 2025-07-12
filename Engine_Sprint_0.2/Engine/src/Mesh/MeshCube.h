//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef CUBE_MESH_H
#define CUBE_MESH_H

#include "Mesh.h"
#include "BufferVBV.h"
#include "BufferIBV.h"

namespace Azul
{
	class MeshCube : public Mesh
	{
	public:
		MeshCube();
		MeshCube(const MeshCube&) = delete;
		MeshCube& operator = (MeshCube&) = delete;
		virtual ~MeshCube();

		virtual void ActivateMesh() override;
		virtual void RenderIndexBuffer() override;

		BufferVBV VBVBuffer_pos;
		BufferVBV VBVBuffer_color;
		BufferVBV VBVBuffer_norm;
		BufferVBV VBVBuffer_tex;

		BufferIBV IBVBuffer;
	};
}


#endif

// --- End of File ---
