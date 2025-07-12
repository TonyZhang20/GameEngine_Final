//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef BUFFER_PIXEL_SHADER_H
#define BUFFER_PIXEL_SHADER_H

#include <d3d11.h>
#include "ShaderMappings.h"

namespace Azul
{
	class BufferPixelShader
	{
	public:
		BufferPixelShader() = delete;
		BufferPixelShader(const BufferPixelShader &r) = delete;
		BufferPixelShader &operator=(const BufferPixelShader &) = delete;
		virtual ~BufferPixelShader();

		BufferPixelShader(uint32_t numBytes, void *pData);

		void SetActive();

	private:
		void privCreate(void *pData);

		// ----------------------
		//  Data
		// ----------------------
	public:
		uint32_t		  codeSize;
		ID3D11PixelShader *poPixelShader;
		bool              bCreate;
	};
}

#endif

//--- End of File ---
