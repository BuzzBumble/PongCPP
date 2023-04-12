#include "Ball.h"

const float Ball::DEFAULT_SPEED = 5.0f;
const float Ball::SPEED_MULTI = 1.2f;
const float Ball::SPEED_TRANSFER_RATIO = 0.5f;

Ball::Ball(float radius, Color fillColor, Paddle& p1, Paddle& p2) :
	radius(radius),
	fillColor(fillColor),
	angle(0.0f),
	speed(DEFAULT_SPEED),
	paddle1(p1),
	paddle2(p2) {
	pos = Vector2{ SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f };
	direction = Vector2{ -1.0, 0 };
};

void Ball::Update() {
	Draw();
	Move();
}

void Ball::Init() {
	angle = computeStartingAngle(false);
	computeDirectionVector();
}

void Ball::Draw() {
	DrawCircleV(pos, radius, fillColor);
}

void Ball::Move() {
	Vector2 velocity = Vector2{ direction.x * speed, direction.y * speed };
	pos = Vector2{ pos.x + velocity.x, pos.y + velocity.y };
	if (checkCollisionWall()) {
		collideWithWall();
	}
	if (checkCollisionPaddle(paddle1)) {
		collideWithPaddle(paddle1);
	}
	if (checkCollisionPaddle(paddle2)) {
		collideWithPaddle(paddle2);
	}
}

void Ball::Reset() {
	pos.x = SCREEN_WIDTH / 2.0f;
	pos.y = SCREEN_HEIGHT / 2.0f;
}

bool Ball::checkCollisionWall() {
	float bottomY = SCREEN_HEIGHT - radius;
	float topY = radius;

	if (pos.y >= bottomY || pos.y <= radius) {
		return true;
	}

	return false;
}

void Ball::collideWithWall() {
	reflectAngleHorizontal();
}

bool Ball::checkCollisionPaddle(Paddle& paddle) {
	return CheckCollisionCircleRec(pos, radius + 2.0f, paddle.GetRect()) && paddle.IsCollidable();
}

void Ball::collideWithPaddle(Paddle& paddle) {
	Paddle::Direction paddleDir = paddle.GetDirection();
	reflectAngleVertical();
	paddle.DisableCollision(10);
}

float Ball::computeStartingAngle(bool goRight) {
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

void Ball::computeDirectionVector() {
	// Why didn't I do this in radians
	int quadrant = getAngleQuadrant();
	float x;
	float y;
	float normalAngle = computeNormalAngle(angle) * DEG2RAD;
	switch (quadrant) {
	case 0:;
		x = std::cos(angle * DEG2RAD);
		y = std::sin(angle * DEG2RAD) * -1;
		break;
	case 1:
		x = std::cos(normalAngle) * -1;
		y = std::sin(normalAngle) * -1;
		break;
	case 2:
		x = std::cos(normalAngle) * -1;
		y = std::sin(normalAngle);
		break;
	case 3:
		x = std::cos(normalAngle);
		y = std::sin(normalAngle);
		break;
	default:
		normalAngle = 0;
		x = 0;
		y = 0;
		break;
	}
	std::cout << "NEW ANGLE: " << normalAngle * RAD2DEG << std::endl;
	direction.x = x;
	direction.y = y;
}

// When the ball hits a horizontal surface
void Ball::reflectAngleHorizontal() {
	angle = 360.0f - angle;
	computeDirectionVector();
}

// When the ball hits a vertical surface
void Ball::reflectAngleVertical() {
	// 360 - angle - 180 to reflect on horizontal then flip direction
	float newAngle = 180.0f - angle;
	if (newAngle < 0) {
		newAngle = 360.0f + newAngle;
	}
	angle = newAngle;
	computeDirectionVector();
}

float Ball::computeNormalAngle(float originalAngle) {
	int quadrant = getAngleQuadrant();
	switch (quadrant) {
	case 0:
		return originalAngle;
	case 1:
		return 180.0f - originalAngle;
	case 2:
		return originalAngle - 180.0f;
	case 3:
		return 360.0f - originalAngle;
	default:
		return originalAngle;
	}
}

int Ball::getAngleQuadrant() {
	return static_cast<int>(angle / 90.0f);
}