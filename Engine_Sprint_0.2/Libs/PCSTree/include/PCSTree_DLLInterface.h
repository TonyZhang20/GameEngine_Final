//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef PCSTREE_DLL_INTERFACE_H
#define PCSTREE_DLL_INTERFACE_H

#ifdef PCSTREE_USE_DLL
#ifdef PCSTREE_LIBRARY_EXPORTS
#define PCSTREE_LIBRARY_API __declspec(dllexport)
#else
#define PCSTREE_LIBRARY_API __declspec(dllimport)
#endif
#else
#define PCSTREE_LIBRARY_API
#endif

#endif

// ---  End of File ---
