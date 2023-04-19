#pragma once
#include "raylib.h"
#include "common.h"
#include "Drawable.h"


class Canvas {
private:
	static Canvas* instancePtr;
	static Color BACKGROUND_COLOR;
	Canvas() {};

public:
	Canvas(const Canvas& canvasObj) = delete;

	static Canvas* GetInstance();

	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 450;

	void Init();
	void Clear();
};