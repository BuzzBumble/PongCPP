#pragma once
#include "raylib.h"
#include "Drawable.h"


class Canvas {
private:
	static Canvas* instancePtr;
	Canvas() {};

public:
	Canvas(const Canvas& canvasObj) = delete;

	static Canvas* getInstance();

	static Color BACKGROUND_COLOR;

	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 450;
};