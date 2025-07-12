#ifndef PCSMAN_BASE_H
#define PCSMAN_BASE_H

#include "PCSNode.h"
#include "PCSTree.h"
#include "PCSTreeIterator.h"
#include "PCSTreeForwardIterator.h"
#include "PCSTreeReverseIterator.h"

namespace Azul
{
	class PCSManBase
	{
	protected:
		//----------------------------------------------------------------------
		// Constructor
		//----------------------------------------------------------------------
		PCSManBase(PCSTree* poActive, PCSTree* poReserve, int InitialNumReserved = 5, int DeltaGrow = 2);
		virtual ~PCSManBase();

		//----------------------------------------------------------------------
		// Base methods - called in Derived class but lives in Base
		//----------------------------------------------------------------------
		void baseSetReserve(int reserveNum, int reserveGrow);

		PCSNode* baseAdd(PCSNode* parent);

		PCSNode* baseFind(PCSNode* pNodeTarget);

		void baseRemove(PCSNode* pNodeBase);

		void baseDump();

		void baseDestroy();

		//----------------------------------------------------------------------
		// Abstract methods - the "contract" Derived class must implement
		//----------------------------------------------------------------------
		virtual PCSNode* derivedCreateNode() = 0;

		//----------------------------------------------------------------------
		// Protected methods - helpers
		//----------------------------------------------------------------------
		void proFillReservedPool(int count);

		//----------------------------------------------------------------------
		// Data:
		//----------------------------------------------------------------------
		PCSTree* poActive;
		PCSTree* poReserve;

		int mDeltaGrow;
		int mTotalNumNodes;
		int mNumReserved;
		int mNumActive;

	};
}

#endif