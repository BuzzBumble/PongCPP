#include "Ball.h"

const float Ball::DEFAULT_SPEED = 5.0f;

Ball::Ball(float radius, Color fillColor) :
	radius(radius),
	fillColor(fillColor) {
	speed = DEFAULT_SPEED;
	pos = Vector2{ SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f };
}

void Ball::Draw() {
	DrawCircleV(pos, radius, fillColor);
}

void Ball::CollideWithPaddle(Paddle& paddle) {

}

bool Ball::CollideWithWallBottom() {
	return false;
}

bool Ball::CollideWithWallTop() {
	return false;
}

htrdhtrd