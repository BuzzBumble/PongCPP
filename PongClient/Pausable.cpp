#include "Pausable.h"

Pausable::Pausable() :
	paused(true) {
}

void Pausable::Pause() {
	paused = true;
}

void Pausable::Unpause() {
	paused = false;
}

bool Pausable::IsPaused() {
	return paused;
}