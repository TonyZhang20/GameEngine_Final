//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef BUFFER_INPUT_LAYOUT_H
#define BUFFER_INPUT_LAYOUT_H

#include <d3d11.h>
#include "ShaderMappings.h"

namespace Azul
{
	class BufferInputLayout
	{
	public:
		BufferInputLayout() = delete;
		BufferInputLayout(const BufferInputLayout &r) = delete;
		BufferInputLayout &operator=(const BufferInputLayout &) = delete;
		virtual ~BufferInputLayout();

		BufferInputLayout(uint32_t _numBytes,
						  void *pData,
						  D3D11_INPUT_ELEMENT_DESC *pDesc,
						  unsigned int _DescSize);

		void SetActive();

	private:
		void privCreate(void *pData);

		// ----------------------
		//  Data
		// ----------------------
	public:
		uint32_t		          codeSize;
		ID3D11InputLayout         *poInputLayout;
		D3D11_INPUT_ELEMENT_DESC  *pDesc;
		unsigned int              DescSize;
		bool                      bCreate;
	};
}

#endif

//--- End of File ---
