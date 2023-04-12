// Game.cpp : Defines the entry point for the application.
//

#include "Game.h"

using namespace std;

int main(void)
{
	// Initialization
	//--------------------------------------------------------------------------------------

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong");

	SetTargetFPS(60);

	Vector2 paddleSize{ 15, 100 };
	Vector2 paddlePos{ 50, (SCREEN_HEIGHT / 2.0) - (paddleSize.y / 2.0) };
	Paddle p1{ paddleSize, paddlePos, WHITE };
	Ball ball{ 5.0f, RED };
	ball.Init();

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		BeginDrawing();
		ClearBackground(BLACK);
		p1.Draw();
		p1.DrawPivot();

		ball.Draw();
		ball.Move();

		if (IsKeyDown(KEY_DOWN)) {
			p1.MoveDown();
		}

		if (IsKeyDown(KEY_UP)) {
			p1.MoveUp();
		}

		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			ball.Reset();
		}

		EndDrawing();

	}

	CloseWindow();

	return 0;
}