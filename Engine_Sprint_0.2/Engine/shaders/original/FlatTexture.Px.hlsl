//--------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//--------------------------------------------------------------


Texture2D mainTexture : register(t0);

SamplerState aSampler : register(s0);

// -------------------------------------
//  Pixel Shader Input Sematics
//        TEXCOORD - uv tex coord
// -------------------------------------
struct PixelShaderInput
{
	float2 tex : TEXCOORD;
};

// --------------------------------------------------------
//  Pixel Shader Main()
//      SV_TARGET - System Value Target
//                  output stored in a render target 0  (only one target)
// --------------------------------------------------------
float4 main(PixelShaderInput inData ) : SV_TARGET
{
	return mainTexture.Sample(aSampler, inData.tex);
}


// --- End of File ---
