//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef STRING_THIS_H
#define STRING_THIS_H

#include "Mesh.h"
#include "Camera.h"
#include "ShaderObject.h"
#include "TextureObject.h"

namespace Azul
{
	class StringThis
	{
	public:
		static const unsigned int BUFFER_SIZE = 64;
	public:

		StringThis(Mesh::Name);
		StringThis(ShaderObject::Name);
		StringThis(Camera::Name);
		StringThis(TextureObject::Name);

		operator char* ();

		// data:
		char buffer[BUFFER_SIZE];
	};

#define StringMe(x)  ((char *)StringThis(x)) 
}


#endif

// --- End of File ---
