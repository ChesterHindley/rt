#pragma once

#include <chrono>
#include <array>

template <typename T = std::chrono::high_resolution_clock>
class ScopeTimer
{
	T::time_point start;
public:
	ScopeTimer() {
		start = T::now();
	}
	~ScopeTimer() {
		using Ms = std::chrono::milliseconds;
		std::print("Time taken: {:.3f} seconds\n", (std::chrono::duration_cast<Ms>(T::now() - start)).count()/1000.f);

	}
};

