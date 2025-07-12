#ifndef TEXTURE_MANAGER_MAN_H
#define TEXTURE_MANAGER_MAN_H

#include "ManBase.h"
#include "TextureObject.h"

namespace Azul
{
	class TextureManager : public ManBase
	{
	public:
		static void Create(int reserveNum = 0, int reserveGrow = 1);
		static void Destroy();

		static TextureObject* Load(TextureObject::Name name);

		static TextureObject* RequireTexture(TextureObject::Name name);
		static TextureObject* Find(TextureObject::Name name);

		static void Remove(TextureObject* pNode);
		static void Dump();

	private:
		static TextureManager* privGetInstance();

		~TextureManager();
		TextureManager(int reserveNum, int reserveGrow);

		//----------------------------------------------------------------------
		// Override Abstract methods
		//----------------------------------------------------------------------
	protected:
		DLink* derivedCreateNode() override;

		//----------------------------------------------------------------------
		// Data: unique data for this manager 
		//----------------------------------------------------------------------
	private:
		TextureObject* poNodeCompare;
		static TextureManager* posInstance;
	};
}


#endif