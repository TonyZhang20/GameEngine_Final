#ifndef MATH_EXPORTAPI_H
#define MATH_EXPORTAPI_H

#ifdef MATH_USE_DLL
	#ifdef MATHLIBRARY_EXPORTS
		#define MATHLIBRARY_API __declspec(dllexport)
	#else
		#define MATHLIBRARY_API __declspec(dllimport)
	#endif // MATHLIBRARY_EXPORTS
#else
	#define MATH_LIBRARY_API
#endif // MATH_USE_DLL

#endif 