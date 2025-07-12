//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef SHADER_IBV_BUFFER_H
#define SHADER_IBV_BUFFER_H

#include <d3d11.h>
#include "ShaderMappings.h"

namespace Azul
{
	class BufferIBV
	{
	public:
		BufferIBV();
		BufferIBV(const BufferIBV& r) = delete;
		BufferIBV& operator=(const BufferIBV&) = delete;
		virtual ~BufferIBV();

		BufferIBV(size_t numBytes, void* pData);

		void SetActive();
		void Initialize(size_t numBytes, void* pData);
	private:
		void privCreate(void* pData);

		// ----------------------
		//  Data
		// ----------------------
	public:
		size_t		 numBytes;
		ID3D11Buffer* poBufferIBV;
		bool bCreate;
	};
}

#endif

//--- End of File ---

