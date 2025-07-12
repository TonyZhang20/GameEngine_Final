//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "BufferCBV_vs.h"
#include "StateDirectXMan.h"

namespace Azul
{
	BufferCBV_vs::BufferCBV_vs(size_t _structSize)
		: structSize{ _structSize },
		poBufferCBV{ nullptr },
		bCreate{ false }
	{
		this->privCreate(_structSize);
	}

	void BufferCBV_vs::privCreate(size_t _structSize)
	{
		// in case set was called before
		assert(this->bCreate == false);
		this->bCreate = true;

		this->structSize = _structSize;
		assert(structSize > 0);

		D3D11_BUFFER_DESC BufferDesc{ 0 };

		//  shader resource
		BufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		BufferDesc.ByteWidth = this->structSize;
		BufferDesc.CPUAccessFlags = 0;
		BufferDesc.Usage = D3D11_USAGE_DEFAULT;
		BufferDesc.MiscFlags = 0;
		BufferDesc.StructureByteStride = 0;

		HRESULT hr;
		hr = StateDirectXMan::GetDevice()->CreateBuffer(&BufferDesc,
														nullptr,
														&this->poBufferCBV);
		assert(SUCCEEDED(hr));
		assert(this->poBufferCBV);
	}

	void BufferCBV_vs::Transfer(void* pBuff)
	{
		// in case set was called before
		assert(this->bCreate == true);
		assert(pBuff);

		StateDirectXMan::GetContext()->UpdateSubresource(poBufferCBV,
															0,
															nullptr,
															pBuff,
															0,
															0);
	}

	void BufferCBV_vs::SetActive(ConstantBufferSlot slot)
	{

		// slow down... check this function (VS,CS,PS) types
		StateDirectXMan::GetContext()->VSSetConstantBuffers((uint32_t)slot,
															1,
															&this->poBufferCBV);

	}

	BufferCBV_vs::~BufferCBV_vs()
	{
		SafeRelease(this->poBufferCBV);
	}

}

//--- End of File ---