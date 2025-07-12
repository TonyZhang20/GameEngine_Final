//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef ENGINE_MATH_VEC3_PROXY_H
#define ENGINE_MATH_VEC3_PROXY_H

namespace Azul
{
	// Vector related proxies here:

	struct Vec3Proxy
	{
	public:

		// Suggested inteface:

		MATHLIBRARY_API Vec3Proxy(float a, float b, float c);
		MATHLIBRARY_API Vec3Proxy() = delete;
		MATHLIBRARY_API Vec3Proxy(const Vec3Proxy &) = default;
		MATHLIBRARY_API Vec3Proxy &operator = (const Vec3Proxy &) = default;
		MATHLIBRARY_API ~Vec3Proxy() = default;

		MATHLIBRARY_API operator float() const;

		MATHLIBRARY_API float operator * (const Vec3Proxy &r) const;

		MATHLIBRARY_API bool operator > (const Vec3Proxy &r) const;
		MATHLIBRARY_API bool operator < (const Vec3Proxy &r) const;
		MATHLIBRARY_API bool operator == (const Vec3Proxy &r) const;
		MATHLIBRARY_API bool operator >= (const Vec3Proxy &r) const;
		MATHLIBRARY_API bool operator <= (const Vec3Proxy &r) const;
		MATHLIBRARY_API bool operator != (const Vec3Proxy &r) const;

	private:
		float x;
		float y;
		float z;
	};

}

#endif

//--- End of File ---
