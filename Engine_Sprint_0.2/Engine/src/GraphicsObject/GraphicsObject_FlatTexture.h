//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef GRAPHICS_OBJECT_FLAT_TEXTURE_H
#define GRAPHICS_OBJECT_FLAT_TEXTURE_H

#include "GraphicsObject.h"
#include "TextureObject.h"

namespace Azul
{

	class GraphicsObject_FlatTexture :public GraphicsObject
	{
	public:
		GraphicsObject_FlatTexture(Mesh *mesh, ShaderObject *pShaderObj, TextureObject::Name texName);

		GraphicsObject_FlatTexture() = delete;
		GraphicsObject_FlatTexture(const GraphicsObject_FlatTexture &) = delete;
		GraphicsObject_FlatTexture &operator = (const GraphicsObject_FlatTexture &) = delete;
		virtual ~GraphicsObject_FlatTexture() = default;

		// Rendermaterial contract
		virtual void SetState() override;
		virtual void SetDataGPU() override;
		virtual void Draw() override;
		virtual void RestoreState() override;

		// ---------------------
		// Data
		// ---------------------

		TextureObject *pTex;

	};

}

#endif


// --- End of File ---
