#include "Canvas.h"

Color Canvas::BACKGROUND_COLOR = BLACK;
Canvas* Canvas::instancePtr = NULL;

Canvas* Canvas::GetInstance() {
	if (instancePtr == NULL) {
		instancePtr = new Canvas();
	}
	return instancePtr;
}

void Canvas::Init() {
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong");

	SetTargetFPS(GLOBAL_FRAME_RATE);
}

void Canvas::Clear() {
	ClearBackground(BACKGROUND_COLOR);
}