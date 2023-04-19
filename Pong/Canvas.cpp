#include "Canvas.h"

Color Canvas::BACKGROUND_COLOR = BLACK;
Canvas* Canvas::instancePtr = NULL;
const float Canvas::SCORE_OFFSET_X = 20.0f;
const float Canvas::SCORE_OFFSET_Y = 20.0f;

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

void Canvas::DrawScore(int p1Score, int p2Score) {
	
}