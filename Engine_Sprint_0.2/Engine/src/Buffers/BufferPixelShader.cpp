//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "BufferPixelShader.h"
#include "StateDirectXMan.h"
#include "ShaderObject.h"

namespace Azul
{
	BufferPixelShader::BufferPixelShader(uint32_t _numBytes, void *pData)
		: codeSize { _numBytes },
		poPixelShader { nullptr },
		bCreate { false }
	{
		assert(pData);
		this->privCreate(pData);
	}

	void BufferPixelShader::privCreate(void *pData)
	{
		// in case set was called before
		assert(this->bCreate == false);
		this->bCreate = true;

		assert(pData);

		HRESULT hr;
		hr = StateDirectXMan::GetDevice()->CreatePixelShader(pData,
															  this->codeSize,
															  nullptr,
															  &this->poPixelShader);
		assert(SUCCEEDED(hr));
		assert(this->poPixelShader);

		//assert(std::string("ps_5_0") == (ShaderObject::GetLatestProfile_PixelShader()));

	}

	void BufferPixelShader::SetActive()
	{
		// slow down... check this function 
		StateDirectXMan::GetContext()->PSSetShader(this->poPixelShader, nullptr, 0);
	}

	BufferPixelShader::~BufferPixelShader()
	{
		SafeRelease(this->poPixelShader);
	}

}

//--- End of File ---
