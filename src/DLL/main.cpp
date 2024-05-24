#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <cstdint>
#include <thread>
#include <chrono>
#include <atomic>

#include "globals.h"
#include "features/features.h"

void SkillSync(const HMODULE instance) noexcept
{
	const auto client = reinterpret_cast<std::uintptr_t>(GetModuleHandle("client.dll"));

	FeaturesRun(client);

	// Uninject dll
	FreeLibraryAndExitThread(instance, 0);
}

// Entry point
int __stdcall DllMain(
	const HMODULE instance,
	const std::uintptr_t reason,
	const void* reserved
)
{
	// DLL_PROCESS_ATTACH
	if (reason == 1) {
		DisableThreadLibraryCalls(instance);

		// Create SkillSync Thread
		const auto thread = CreateThread(
			nullptr,
			0,
			reinterpret_cast<LPTHREAD_START_ROUTINE>(SkillSync),
			instance,
			0,
			nullptr
		);

		if (thread != NULL)
		{
			CloseHandle(thread);
		}
	}

	return 1;
}