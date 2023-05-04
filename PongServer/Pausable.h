#pragma once
#include "common.h"
#include "Drawable.h"
#include "raylib.h"

class Pausable {
public:
	Pausable();
	void Pause();
	void Unpause();
	bool IsPaused();
protected:
	bool paused;
};