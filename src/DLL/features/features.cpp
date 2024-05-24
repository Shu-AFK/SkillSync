#include "features.h"
#include "../globals.h"

#include <thread>
#include <vector>

void FeaturesRun(std::uintptr_t client) noexcept
{
	std::vector<std::thread> threads;

	// Creates threads of all the features
	threads.emplace_back(movement::BunnyHop, client);

	for (size_t i = 0; i < threads.size(); i++)
	{
		threads[i].detach();
	}

	while (!GetAsyncKeyState(VK_END))
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(DELAY));
	}

	forceStop = true;
}