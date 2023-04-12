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
	Paddle p1{ paddleSize, paddlePos, WHITE, WHITE };

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		BeginDrawing();
		ClearBackground(BLACK);
		p1.Draw();
		p1.DrawPivot();
		if (IsKeyDown(KEY_DOWN)) {
			p1.MoveDown();
		}

		if (IsKeyDown(KEY_UP)) {
			p1.MoveUp();
		}

		EndDrawing();

	}

	CloseWindow();

	return 0;
}