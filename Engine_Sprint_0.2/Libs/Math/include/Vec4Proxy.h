//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef ENGINE_MATH_VEC4_PROXY_H
#define ENGINE_MATH_VEC4_PROXY_H

namespace Azul
{
	// Vector related proxies here:

	struct Vec4Proxy
	{
	public:

		// Suggested inteface:

		MATHLIBRARY_API Vec4Proxy(float a, float b, float c, float d);

		MATHLIBRARY_API Vec4Proxy() = delete;
		MATHLIBRARY_API Vec4Proxy(const Vec4Proxy &) = default;
		MATHLIBRARY_API Vec4Proxy &operator = (const Vec4Proxy &) = default;
		MATHLIBRARY_API ~Vec4Proxy() = default;

		MATHLIBRARY_API operator float() const;

		MATHLIBRARY_API float operator * (const Vec4Proxy &r) const;

		MATHLIBRARY_API bool operator > (const Vec4Proxy &r) const;
		MATHLIBRARY_API bool operator < (const Vec4Proxy &r) const;
		MATHLIBRARY_API bool operator == (const Vec4Proxy &r) const;

		MATHLIBRARY_API bool operator >= (const Vec4Proxy &r) const;
		MATHLIBRARY_API bool operator <= (const Vec4Proxy &r) const;
		MATHLIBRARY_API bool operator != (const Vec4Proxy &r) const;

	private:
		float x;
		float y;
		float z;
		float w;
	};

}

#endif

//--- End of File ---
