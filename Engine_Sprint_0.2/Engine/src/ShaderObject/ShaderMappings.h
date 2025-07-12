//--------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//--------------------------------------------------------------

#ifndef SHADER_MAPPINGS_H
#define SHADER_MAPPINGS_H

namespace Azul
{

	enum class VertexSlot : uint32_t
	{
		Position,   // 0
		Color,      // 1
		Norm,       // 2
		TexCoord   // 3
	};

	// in shaders these are CBV slot "bx"
	enum class ConstantBufferSlot : uint32_t
	{
		Projection,   // 0
		View,         // 1
		World,         // 2

		Color,   // 3
		LightPos      //4
	};

	// in shaders these are RSV slot "tx"
	enum class ShaderResourceBufferSlot : uint32_t
	{
		TexA      // slot 0  
	};

	// in shaders these are Sampler slot "sx"
	enum class ShaderSamplerSlot : uint32_t
	{
		SampleA   // slot 0
	};



}

#endif

// --- End of File ---