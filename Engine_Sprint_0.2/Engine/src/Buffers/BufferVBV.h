//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef SHADER_VBV_BUFFER_H
#define SHADER_VBV_BUFFER_H

#include <d3d11.h>
#include "ShaderMappings.h"

namespace Azul
{
	class BufferVBV
	{
	public:
		BufferVBV();
		BufferVBV(const BufferVBV& r) = delete;
		BufferVBV& operator=(const BufferVBV&) = delete;
		virtual ~BufferVBV();

		BufferVBV(uint32_t numBytes, uint32_t _strideSize, void* pData);

		void SetActive(VertexSlot slot);
		void Initialize(uint32_t numBytes, uint32_t _strideSize, void* pData);

	private:
		void privCreate(void* pData);

		// ----------------------
		//  Data
		// ----------------------
	public:
		uint32_t	 numBytes;
		uint32_t	 strideSize;
		uint32_t	 offset;
		ID3D11Buffer* poBufferVBV;
		bool bCreate;
	};
}

#endif

//--- End of File ---
