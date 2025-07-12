//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "ShaderObjectNodeManager.h"
#include "ShaderObject_Null.h"
#include "ManBase.h"
#include "DLinkMan.h"

namespace Azul
{

	ShaderObjectNodeManager* ShaderObjectNodeManager::posInstance = nullptr;

	//----------------------------------------------------------------------
	// Constructor
	//----------------------------------------------------------------------
	ShaderObjectNodeManager::ShaderObjectNodeManager(int reserveNum, int reserveGrow)
		: ManBase(new DLinkMan(), new DLinkMan(), reserveNum, reserveGrow)
	{
		// Preload the reserve
		this->proFillReservedPool(reserveNum);

		// initialize derived data here
		ShaderObject* pShaderObject = new ShaderObject_Null();
		assert(pShaderObject);

		this->poNodeCompare = new ShaderObjectNode();
		assert(this->poNodeCompare);

		this->poNodeCompare->Set(pShaderObject);
	}

	ShaderObjectNodeManager::~ShaderObjectNodeManager()
	{
		delete this->poNodeCompare;
		this->poNodeCompare = nullptr;

		// iterate through the list and delete
		Iterator* pIt = this->baseGetActiveIterator();

		DLink* pNode = pIt->First();

		// Walk through the nodes
		while (!pIt->IsDone())
		{
			ShaderObjectNode* pDeleteMe = (ShaderObjectNode*)pIt->Curr();
			pNode = pIt->Next();
			delete pDeleteMe;
		}

		pIt = this->baseGetReserveIterator();

		pNode = pIt->First();

		// Walk through the nodes
		while (!pIt->IsDone())
		{
			ShaderObjectNode* pDeleteMe = (ShaderObjectNode*)pIt->Curr();
			pNode = pIt->Next();
			delete pDeleteMe;
		}
	}

	//----------------------------------------------------------------------
	// Static Methods
	//----------------------------------------------------------------------
	void ShaderObjectNodeManager::Create(int reserveNum, int reserveGrow)
	{
		// make sure values are ressonable 
		assert(reserveNum >= 0);
		assert(reserveGrow > 0);

		// initialize the singleton here
		assert(posInstance == nullptr);

		// Do the initialization
		if (posInstance == nullptr)
		{
			posInstance = new ShaderObjectNodeManager(reserveNum, reserveGrow);
		}
	}

	void ShaderObjectNodeManager::Destroy()
	{
		ShaderObjectNodeManager* pMan = ShaderObjectNodeManager::privGetInstance();
		assert(pMan != nullptr);
		AZUL_UNUSED_VAR(pMan);

		delete ShaderObjectNodeManager::posInstance;
		ShaderObjectNodeManager::posInstance = nullptr;
	}

	ShaderObjectNode* ShaderObjectNodeManager::Add(ShaderObject* pMesh)
	{
		ShaderObjectNodeManager* pMan = ShaderObjectNodeManager::privGetInstance();

		assert(pMesh);

		ShaderObjectNode* pNode = (ShaderObjectNode*)pMan->baseAddToFront();
		assert(pNode != nullptr);

		// Initialize the date
		pNode->Set(pMesh);

		return pNode;
	}

	ShaderObjectNode* ShaderObjectNodeManager::Find(ShaderObject::Name _name)
	{
		ShaderObjectNodeManager* pMan = ShaderObjectNodeManager::privGetInstance();
		assert(pMan != nullptr);

		// Compare functions only compares two Nodes

		// So:  Use the Compare Node - as a reference
		//      use in the Compare() function
		ShaderObject* pShaderObject = pMan->poNodeCompare->GetShaderObject();
		assert(pShaderObject);

		pShaderObject->name = _name;

		ShaderObjectNode* pData = (ShaderObjectNode*)pMan->baseFind(pMan->poNodeCompare);
		return pData;
	}

	void ShaderObjectNodeManager::Remove(ShaderObjectNode* pNode)
	{
		assert(pNode != nullptr);

		ShaderObjectNodeManager* pMan = ShaderObjectNodeManager::privGetInstance();
		assert(pMan != nullptr);

		pMan->baseRemove(pNode);
	}

	void ShaderObjectNodeManager::Dump()
	{
		ShaderObjectNodeManager* pMan = ShaderObjectNodeManager::privGetInstance();
		assert(pMan != nullptr);

		pMan->baseDump();
	}

	//----------------------------------------------------------------------
	// Private methods
	//----------------------------------------------------------------------
	ShaderObjectNodeManager* ShaderObjectNodeManager::privGetInstance()
	{
		// Safety - this forces users to call Create() first before using class
		assert(posInstance != nullptr);

		return posInstance;
	}

	//----------------------------------------------------------------------
	// Override Abstract methods
	//----------------------------------------------------------------------
	DLink* ShaderObjectNodeManager::derivedCreateNode()
	{
		DLink* pNodeBase = new ShaderObjectNode();
		assert(pNodeBase != nullptr);

		return pNodeBase;
	}

}
// --- End of File ---




