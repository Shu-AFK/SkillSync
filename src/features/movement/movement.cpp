#include "movement.h"
#include "../../globals.h"

#include <thread>

void movement::BunnyHop(uintptr_t client) noexcept
{
	// The main BunnyHop loop, while the END key is not pressed
	while (!forceStop.load())
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(DELAY));

		// Make sure space bare is pressed
		if (!GetAsyncKeyState(VK_SPACE))
			continue;

		const auto localPawn = *reinterpret_cast<std::uintptr_t*>(client + offset::dwLocalPlayerPawn);
		// Checking if player is valid
		if (localPawn == NULL)
			continue;

		const auto health = *reinterpret_cast<std::int32_t*>(localPawn + offset::m_iHealth);
		// Checking if player is alive
		if (health == NULL)
			continue;

		const auto flags = *reinterpret_cast<std::int32_t*>(localPawn + offset::m_fFlags);
		// Checking if player is on the ground
		(flags & (1 << 0)) ?
			*reinterpret_cast<std::uintptr_t*>(client + offset::jump) = 65537 : // Force jump
			*reinterpret_cast<std::uintptr_t*>(client + offset::jump) = 256;
	}
}