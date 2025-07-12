//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef SHADER_CBV_BUFFER_H
#define SHADER_CBV_BUFFER_H

#include <d3d11.h>
#include "ShaderMappings.h"

namespace Azul
{
	class BufferCBV_vs
	{
	public:
		BufferCBV_vs() = delete;
		BufferCBV_vs(const BufferCBV_vs& r) = delete;
		BufferCBV_vs& operator=(const BufferCBV_vs&) = delete;
		virtual ~BufferCBV_vs();

		BufferCBV_vs(size_t structSize);

		void Transfer(void* pBuff);
		void SetActive(ConstantBufferSlot slot);

	private:
		void privCreate(size_t structSize);

		// ----------------------
		//  Data
		// ----------------------
	public:
		size_t structSize;
		ID3D11Buffer* poBufferCBV;
		bool bCreate;
	};
}

#endif

//--- End of File ---