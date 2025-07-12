//--------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//--------------------------------------------------------------

#ifndef ANIM_TIMER_H
#define ANIM_TIMER_H

/*
 * class AnimTimer
 * Measures real durations of time in terms of Time.
 *
 * The AnimTimer interface you see here owes itself to Matlab.
 * You only measure segements of time with a AnimTimer.  Use tic() to
 * mark the beginning of the segment.  Use toc() to mark the end.
 *
 * toc() always returns the amount of time that has elapsed since tic()
 * was called.  If you never call tic() on your AnimTimer then toc() will
 * return @link Time::Time() zero @endlink.
 *
 *
 * Example
 *
 *    #include "AnimTimer.h"
 *
 *    // Create a AnimTimer.
 *    AnimTimer AnimTimer;
 *
 *    // Mark our begin time.
 *    AnimTimer.tic();
 *
 *    // Do something for a while.
 *    ...
 *
 *    // Measure how much time has gone by since we called tic().
 *    const Time elapsedTime = AnimTimer.toc();
 *
 *
 */

 //---------------------------------------------------------------------------
 // HEADER FILES:
 //---------------------------------------------------------------------------

#include "AnimTime.h"

#ifdef ANIM_TIME_USE_DLL
#ifdef ANIM_TIME_LIBRARY_EXPORTS
#define ANIM_TIME_LIBRARY_API __declspec(dllexport)
#else
#define ANIM_TIME_LIBRARY_API __declspec(dllimport)
#endif
#else
#define ANIM_TIME_LIBRARY_API
#endif


//---------------------------------------------------------------------------
// TEMPLATE DECLARATION:
//---------------------------------------------------------------------------

namespace Azul
{
	class AnimTimer
	{
	public:
		//-----------------------------------------------------------------
		// Constructors / Destructors
		//-----------------------------------------------------------------

		/* Creates a AnimTimer for the platform you are compiling on. */
		ANIM_TIME_LIBRARY_API AnimTimer();
		ANIM_TIME_LIBRARY_API AnimTimer(const AnimTimer &) = delete;
		ANIM_TIME_LIBRARY_API AnimTimer &operator = (const AnimTimer &) = delete;
		ANIM_TIME_LIBRARY_API ~AnimTimer();

		//-----------------------------------------------------------------
		// Timing Methods
		//-----------------------------------------------------------------

		/*
		* Marks the moment in time that toc() will get measured against.
		* Call tic() to mark the beginning of the segment of time that
		* you want to measure.
		*/
		ANIM_TIME_LIBRARY_API void Tic();

		/*
		* return: The duration of Time that has elapsed since tic() was
		* called.  Returns Time::Time() zero if tic() has
		* never been called on this AnimTimer.
		*/
		ANIM_TIME_LIBRARY_API const AnimTime Toc() const;


	private:
		// static method
		static const AnimTime privGetSystemTime();

		// Data
		AnimTime privTicMark;
	};
}

#endif   // AnimTimer_h

// ---  End of File ---
