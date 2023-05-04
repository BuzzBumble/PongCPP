#include "Ball.h"

const float Ball::DEFAULT_SPEED = 5.0f;
const float Ball::SPEED_MULTI = 1.05f;
const float Ball::SPEED_TRANSFER_RATIO = 0.5f;
float Ball::DEFAULT_RADIUS = 5.0f;
const int Ball::PADDLE_DISABLED_FRAMES = 10;

Ball::Ball(float radius, Color fillColor, Paddle& p1, Paddle& p2) :
	radius(radius),
	fillColor(fillColor),
	speed(DEFAULT_SPEED),
	paddle1(p1),
	paddle2(p2) {
	pos = Vector2{ SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f };
	direction = Vector2{ -1.0, 0 };
};

void Ball::Update() {
	if (!isHidden) {
		Draw();
	}
	if (!paused) {
		Move();
	}
}

void Ball::Init() {
	direction = computeStartingDirection(false);
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
	speed = DEFAULT_SPEED;
}

void Ball::SetDirection(Vector2 vector) {
	direction = vector;
}

void Ball::SetSpeed(float newSpeed) {
	speed = newSpeed;
}

bool Ball::checkCollisionWall() {
	float bottomY = SCREEN_HEIGHT - radius;
	float topY = GAME_TOP + radius;

	if (pos.y >= bottomY || pos.y <= topY) {
		return true;
	}

	return false;
}

void Ball::collideWithWall() {
	SetDirection(direction.ReflectHorizontal());
}

bool Ball::checkCollisionPaddle(const Paddle& paddle) {
	return CheckCollisionCircleRec(pos, radius + 2.0f, paddle.GetRect()) && paddle.IsCollidable();
}

void Ball::collideWithPaddle(Paddle& paddle) {
	Paddle::Direction paddleDir = paddle.GetDirection();
	SetSpeed(speed * SPEED_MULTI);
	SetDirection(direction.ReflectVertical());
	paddle.DisableCollision(PADDLE_DISABLED_FRAMES);
}

// Return 0 when not out of bounds
// 1 if out of bounds on the left
// 2 if out of bounds on the right
int Ball::IsOutOfBounds() {
	if (pos.x < 0) {
		return 1;
	}
	if (pos.x > SCREEN_WIDTH) {
		return 2;
	}
	return 0;
}

Vector2 Ball::computeStartingDirection(bool goRight) {
	float x = goRight ? 1 : -1;
	float y = (static_cast<float>(rand()) / static_cast<float>(RAND_MAX / 2)) - 1;
	
	return Vector2{x, y}.Normalize();
}