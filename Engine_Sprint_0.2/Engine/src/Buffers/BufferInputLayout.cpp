//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "BufferInputLayout.h"
#include "StateDirectXMan.h"
#include "ShaderObject.h"

namespace Azul
{
	BufferInputLayout::BufferInputLayout(uint32_t _numBytes,
										 void *pData,
										 D3D11_INPUT_ELEMENT_DESC *_pDesc,
										 unsigned int _DescSize)
		: codeSize { _numBytes },
		poInputLayout { nullptr },
		pDesc(_pDesc),
		DescSize(_DescSize),
		bCreate { false }
	{
		assert(pData);
		assert(pDesc);
		this->privCreate(pData);
	}

	void BufferInputLayout::privCreate(void *pData)
	{
		// in case set was called before
		assert(this->bCreate == false);
		this->bCreate = true;

		assert(pData);
		assert(pDesc);

		HRESULT hr;
		hr = StateDirectXMan::GetDevice()->CreateInputLayout(this->pDesc,
															  this->DescSize / sizeof(D3D11_INPUT_ELEMENT_DESC),
															  pData,
															  this->codeSize,
															  &this->poInputLayout);
		assert(SUCCEEDED(hr));

		assert(this->poInputLayout);
	}

	void BufferInputLayout::SetActive()
	{
		// slow down... check this function 
		StateDirectXMan::GetContext()->IASetInputLayout(this->poInputLayout);
	}

	BufferInputLayout::~BufferInputLayout()
	{
		SafeRelease(this->poInputLayout);
	}

}

//--- End of File ---
