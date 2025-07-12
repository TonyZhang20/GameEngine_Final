//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef BUFFER_VERTEX_SHADER_H
#define BUFFER_VERTEX_SHADER_H

#include <d3d11.h>
#include "ShaderMappings.h"

namespace Azul
{
	class BufferVertexShader
	{
	public:
		BufferVertexShader() = delete;
		BufferVertexShader(const BufferVertexShader &r) = delete;
		BufferVertexShader &operator=(const BufferVertexShader &) = delete;
		virtual ~BufferVertexShader();

		BufferVertexShader(uint32_t numBytes, void *pData);

		void SetActive();

	private:
		void privCreate(void *pData);

		// ----------------------
		//  Data
		// ----------------------
	public:
		uint32_t		   codeSize;
		ID3D11VertexShader *poVertexShader;
		bool               bCreate;
	};
}

#endif

//--- End of File ---
