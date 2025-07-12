#ifndef MODEL_NULL_H
#define MODEL_NULL_H

#include "Mesh.h"
namespace Azul
{
	class MeshNull : public Mesh
	{
	public:
		MeshNull();
		MeshNull(const MeshNull&) = delete;
		MeshNull& operator=(const MeshNull& other) = delete;
		virtual ~MeshNull();

		virtual void ActivateMesh();
		virtual void RenderIndexBuffer();

	private:

	};
}


#endif

// --- End of File ---
