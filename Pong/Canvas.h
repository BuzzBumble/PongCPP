#pragma once
#include "raylib.h"
#include "common.h"
#include "Drawable.h"


class Canvas {
private:
	static Canvas* instancePtr;
	static Color BACKGROUND_COLOR;
	static const float SCORE_OFFSET_X;
	static const float SCORE_OFFSET_Y;
	Canvas() {};

public:
	Canvas(const Canvas& canvasObj) = delete;

	static Canvas* GetInstance();

	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 450;

	void Init();
	void Clear();
	void DrawScore(int p1Score, int p2Score);
};