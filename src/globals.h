#ifndef SKILLSYNC_GLOBALS_H
#define SKILLSYNC_GLOBALS_H

#include <atomic>

#define DELAY 1 // in miliseconds

extern std::atomic<bool> forceStop;

namespace offset
{
	// offsets.hpp (Client)
	constexpr std::ptrdiff_t dwLocalPlayerPawn = 0x173B568;

	// client.dll.hpp (Player)
	constexpr std::ptrdiff_t m_iHealth = 0x334;
	constexpr std::ptrdiff_t m_fFlags = 0x3D4;

	// buttons.hpp (Player Actions)
	constexpr std::ptrdiff_t jump = 0x17348E0;
}

#endif // SKILLSYNC_GLOBALS_H
