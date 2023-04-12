// Game.cpp : Defines the entry point for the application.
//

#include "Game.h"

using namespace std;

int main(void)
{
	// Initialization
	//--------------------------------------------------------------------------------------

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong");

	SetTargetFPS(GLOBAL_FRAME_RATE);

	Vector2 paddleSize{ 15, 100 };
	Vector2 paddle1Pos{ 50, (SCREEN_HEIGHT / 2.0) - (paddleSize.y / 2.0) };
	Vector2 paddle2Pos{ SCREEN_WIDTH - (50 + paddleSize.x), (SCREEN_HEIGHT / 2.0) - (paddleSize.y / 2.0)};
	Paddle p1{ paddleSize, paddle1Pos, WHITE };
	Paddle p2{ paddleSize, paddle2Pos, WHITE };
	Ball ball{ 5.0f, RED, p1, p2 };
	ball.Init();

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		BeginDrawing();
		ClearBackground(BLACK);
		p1.Update();
		p2.Update();
		ball.Update();

		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			ball.Reset();
		}

		EndDrawing();

	}

	CloseWindow();

	return 0;
}