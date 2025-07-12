#ifndef MESHFILEREADER_H
#define MESHFILEREADER_H

#include "Mesh.h"
#include "BufferVBV.h"
#include "BufferIBV.h"

namespace Azul
{
	class MeshReadFile : public Mesh
	{
	public:
		MeshReadFile(const char* const pWaveName);
		MeshReadFile(const MeshReadFile&) = delete;
		MeshReadFile& operator = (MeshReadFile&) = delete;
		virtual ~MeshReadFile();

		void ReadFile(const char* fileName, char*& datam, DWORD& fileSize);

		virtual void ActivateMesh() override;
		virtual void RenderIndexBuffer() override;

		BufferVBV VBVBuffer_pos;
		BufferVBV VBVBuffer_color;
		BufferVBV VBVBuffer_norm;
		BufferVBV VBVBuffer_tex;

		BufferIBV IBVBuffer;
	};

}


#endif