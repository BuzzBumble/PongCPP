#include "Tick.h"

const std::chrono::milliseconds Tick::MS_PER_TICK = std::chrono::milliseconds(1000) / Tick::TICKS_PER_SECOND;

Tick::Tick() {
	SetNewTick();
}

std::chrono::milliseconds Tick::CurrentTimeInMs() {
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
}

std::chrono::milliseconds Tick::timeSinceLastTick() {
	return CurrentTimeInMs() - lastTickTime;
}

void Tick::SetNewTick() {
	lastTickTime = CurrentTimeInMs();
}

std::chrono::milliseconds Tick::GetLastTickTime() {
	return lastTickTime;
}

void Tick::AddTime(std::chrono::milliseconds ms) {
	lastTickTime += ms;
}
