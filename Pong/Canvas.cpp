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
	DrawScoreBackground();
	std::string p1Str = std::to_string(p1Score);
	std::string p2Str = std::to_string(p2Score);
	DrawText(p1Str.c_str(), 50, 50, 24, WHITE);
	DrawText(p2Str.c_str(), SCREEN_WIDTH - 50, 50, 24, WHITE);
}

void Canvas::DrawScoreBackground() {
	DrawRectangle(0, 0, SCREEN_WIDTH, GAME_TOP, GRAY);
}