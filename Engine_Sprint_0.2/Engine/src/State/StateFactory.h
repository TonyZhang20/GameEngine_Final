//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef STATE_FACTORY_H
#define STATE_FACTORY_H

#include <d3d11.h>

namespace Azul
{
	class StateFactory
	{
	public:
		StateFactory();
		StateFactory(const StateFactory &) = delete;
		StateFactory &operator = (const StateFactory &) = delete;
		virtual ~StateFactory();


		IDXGIFactory *poDXGFactory;
	};

}
#endif 

// --- End of File ---
