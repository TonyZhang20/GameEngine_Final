#ifndef Pyramid_Mesh_H
#define Pyramid_Mesh_H

#include "Mesh.h"
#include "BufferVBV.h"
#include "BufferIBV.h"

namespace Azul
{
	class MeshPyramid : public Mesh
	{
	public:
		MeshPyramid();
		MeshPyramid(const MeshPyramid&) = delete;
		MeshPyramid& operator = (MeshPyramid&) = delete;
		virtual ~MeshPyramid();

		virtual void ActivateMesh() override;
		virtual void RenderIndexBuffer() override;

		BufferVBV VBVBuffer_pos;
		BufferVBV VBVBuffer_color;
		BufferVBV VBVBuffer_tex;
		BufferVBV VBVBuffer_norm;

		BufferIBV IBVBuffer;
	};
}


#endif

// --- End of File ---
