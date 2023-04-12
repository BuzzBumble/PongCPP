#include "Ball.h"

const float Ball::DEFAULT_SPEED = 5.0f;

Ball::Ball(float radius, Color fillColor) :
	radius(radius),
	fillColor(fillColor),
	angle(0.0f),
	speed(DEFAULT_SPEED) { 
	pos = Vector2{ SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f };
	direction = Vector2{ -1.0, 0 };
};

void Ball::Init() {
	angle = ComputeStartingAngle(false);
	std::cout << "Starting angle: " << angle << std::endl;
	ComputeDirectionVector();
}

void Ball::Draw() {
	DrawCircleV(pos, radius, fillColor);
}

void Ball::Move() {
	Vector2 velocity = Vector2{ direction.x * speed, direction.y * speed };
	pos = Vector2{ pos.x + velocity.x, pos.y + velocity.y };
	if (CheckCollisionWall()) {
		CollideWithWall();
	}
}

void Ball::Reset() {
	pos.x = SCREEN_WIDTH / 2.0f;
	pos.y = SCREEN_HEIGHT / 2.0f;
}

void Ball::CollideWithPaddle(Paddle& paddle) {
	
}

bool Ball::CheckCollisionWall() {
	float bottomY = SCREEN_HEIGHT - radius;
	float topY = radius;

	if (pos.y >= bottomY || pos.y <= radius) {
		return true;
	}

	return false;
}

void Ball::CollideWithWall() {
	direction.y *= -1;
}


bool Ball::isCollidingWithPaddle(Paddle& paddle) {
	return CheckCollisionCircleRec(pos, radius, paddle.GetRect());
}

float Ball::ComputeStartingAngle(bool goRight) {
	const float range = 45.0f;
	const float leftStart = 180;
	const float rightStart = 0;

	float randAdditive = static_cast<float>(GetRandomValue(range * -1, range));
	if (goRight) {
		return randAdditive < 0 ? 360 + randAdditive : randAdditive;
	} else {
		return leftStart + randAdditive;
	}
}

void Ball::ComputeDirectionVector() {
	int quadrant = static_cast<int>(angle / 90.0f);
	float x;
	float y;
	float newAngle;
	std::cout << quadrant << std::endl;
	switch (quadrant) {
	case 0:
		x = std::cos(angle * (PI / 180));
		y = std::sin(angle * (PI / 180)) * -1;
		break;
	case 1:
		newAngle = (180.0f - angle) * (PI / 180);
		std::cout << "New Angle: " << newAngle << std::endl;
		x = std::cos(newAngle) * -1;
		y = std::sin(newAngle) * -1;
		break;
	case 2:
		newAngle = (angle - 180.0f) * (PI / 180);
		std::cout << "New Angle: " << newAngle << std::endl;
		x = std::cos(newAngle) * -1;
		y = std::sin(newAngle);
		break;
	case 3:
		newAngle = (360.0f - angle) * (PI / 180);
		x = std::cos(newAngle);
		y = std::sin(newAngle);
		break;
	default:
		x = 0;
		y = 0;
		break;
	}
	std::cout << x << ", " << y << std::endl;
	direction.x = x;
	direction.y = y;
}