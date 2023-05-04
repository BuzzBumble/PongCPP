#pragma once
#include "common.h"

class Pausable {
public:
	Pausable();
	void Pause();
	void Unpause();
	bool IsPaused();
protected:
	bool paused;
};