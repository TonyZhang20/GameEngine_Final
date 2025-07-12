//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "BufferIBV.h"
#include "StateDirectXMan.h"

namespace Azul
{
	BufferIBV::BufferIBV(size_t _numBytes, void* pData)
		: numBytes{ _numBytes },
		poBufferIBV{ nullptr },
		bCreate{ false }
	{
		assert(pData);
		this->privCreate(pData);
	}

	void BufferIBV::privCreate(void* pData)
	{
		// in case set was called before
		assert(this->bCreate == false);
		this->bCreate = true;

		assert(pData);

		// Create and initialize the index buffer.
		D3D11_BUFFER_DESC indexBufferDesc{ 0 };
		D3D11_SUBRESOURCE_DATA resourceData{ 0 };

		indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
		indexBufferDesc.ByteWidth = this->numBytes;
		indexBufferDesc.CPUAccessFlags = 0;
		indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;

		resourceData.pSysMem = pData;

		HRESULT hr;
		hr = StateDirectXMan::GetDevice()->CreateBuffer(&indexBufferDesc,
			&resourceData,
			&this->poBufferIBV);
		assert(SUCCEEDED(hr));
		assert(this->poBufferIBV);

	}

	void BufferIBV::SetActive()
	{
		// slow down... check this function (VS,CS,PS) types
		StateDirectXMan::GetContext()->IASetIndexBuffer(this->poBufferIBV,
			DXGI_FORMAT_R32_UINT,
			0);
	}

	void BufferIBV::Initialize(size_t numBytes, void* pData)
	{
		assert(pData);
		this->numBytes = numBytes;
		
		this->privCreate(pData);
	}

	BufferIBV::BufferIBV():
		numBytes { 0 },
		poBufferIBV{ nullptr },
		bCreate{ false }
	{

	}

	BufferIBV::~BufferIBV()
	{
		SafeRelease(this->poBufferIBV);
	}

}

//--- End of File ---
