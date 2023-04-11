// Game.cpp : Defines the entry point for the application.
//

#include "Game.h"

using namespace std;

int main(void)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 450;

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong");

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(BLACK);
		Vector2 size{ 50, 100 };
		Vector2 pos{ 100, 100 };
		Paddle p1{ size, pos, WHITE, WHITE };
		p1.Draw();

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	CloseWindow();                // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}