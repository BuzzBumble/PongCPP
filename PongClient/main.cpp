#include <iostream>
#include "GameManager.h"
#include "Paddle.h"
#include "Ball.h"

int main() {
	
	float gameHeight = SCREEN_HEIGHT - GAME_TOP;
	float midY = (gameHeight / 2.0f) - (Paddle::DEFAULT_DIMENSIONS.y / 2.0f) + GAME_TOP;
	Paddle p1 = Paddle{ 1, Paddle::DEFAULT_DIMENSIONS, Vector2{Paddle::DEFAULT_OFFSET, midY}, WHITE };
	Paddle p2 = Paddle{ 2, Paddle::DEFAULT_DIMENSIONS, Vector2{SCREEN_WIDTH - (Paddle::DEFAULT_OFFSET + Paddle::DEFAULT_DIMENSIONS.x), midY}, WHITE };
	Ball ball = Ball{ Ball::DEFAULT_RADIUS, RED, p1, p2 };

	GameManager gameManager = GameManager{ p1, p2, ball };
	gameManager.Start();
	
	return 0;
}