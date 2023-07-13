#pragma once
#include <chrono>

class Tick {
public:
	static const int TICKS_PER_SECOND = 60;
	static const std::chrono::milliseconds MS_PER_TICK;


	static std::chrono::milliseconds CurrentTimeInMs();

	std::chrono::milliseconds GetLastTickTime();

	void SetNewTick();

	void AddTime(std::chrono::milliseconds ms);
private:
	std::chrono::milliseconds lastTickTime;
	std::chrono::milliseconds timeSinceLastTick();
};