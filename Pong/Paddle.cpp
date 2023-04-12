#include "Paddle.h"

const float Paddle::DEFAULT_SPEED = 10.0f;
const float Paddle::TARGET_FRAME_TIME = 1.0f / GLOBAL_FRAME_RATE;

Paddle::Paddle(Vector2 dimensions, Vector2 pos, Color fillColor) :
	dimensions(dimensions),
	pos(pos),
	fillColor(fillColor),
	direction(Direction::STILL),
	isCollidable(true),
	frameCounter(0.0f)
{
	speed = DEFAULT_SPEED;
	rect = Rectangle{ pos.x, pos.y, dimensions.x, dimensions.y };
};

float Paddle::GetHeight() {
	return pos.x;
}

float Paddle::GetWidth() {
	return pos.y;
}

const Rectangle& Paddle::GetRect() {
	return rect;
}

const Vector2& Paddle::GetPos() {
	return pos;
}

void Paddle::SetPos(const Vector2& newPos) {
	pos = newPos;
}

void Paddle::SetDirection(const Direction dir) {
	direction = dir;
}

const Paddle::Direction Paddle::GetDirection() {
	return direction;
}

void Paddle::Draw() {
	DrawRectangleV(pos, dimensions, fillColor);
}

const Color& Paddle::GetFillColor() {
	return fillColor;
}

void Paddle::Update() {
	Draw();
	updateRectangle();
	if (!isCollidable) {
		tickDisabledCollision();
	}
	if (IsKeyDown(KEY_DOWN)) {
		MoveDown();
	} else if (IsKeyDown(KEY_UP)) {
		MoveUp();
	} else {
		SetDirection(Direction::STILL);
	}
}

void Paddle::MoveDown() {
	if (IsInBoundsBottom()) {
		pos.y = pos.y + DEFAULT_SPEED;
		SetDirection(Direction::DOWN);
	}
	else {
		pos.y = SCREEN_HEIGHT - dimensions.y;
		SetDirection(Direction::STILL);
	}
}

void Paddle::MoveUp() {
	if (IsInBoundsTop()) {
		pos.y = pos.y - DEFAULT_SPEED;
		SetDirection(Direction::UP);
	}
	else {
		pos.y = 0;
		SetDirection(Direction::STILL);
	}
}

bool Paddle::IsCollidable() {
	return isCollidable;
}

void Paddle::DisableCollision(int frames) {
	frameCounter = frames;
	isCollidable = false;
}

void Paddle::tickDisabledCollision() {
	frameCounter -= GetFrameTime() / TARGET_FRAME_TIME;
	if (frameCounter < 0) {
		isCollidable = true;
	}
}

void Paddle::updateRectangle() {
	rect.x = pos.x;
	rect.y = pos.y;
	rect.width = dimensions.x;
	rect.height = dimensions.y;
}

bool Paddle::IsInBoundsTop() {
	if (pos.y <= 0) {
		return false;
	}
}

bool Paddle::IsInBoundsBottom() {
	if (pos.y + dimensions.y >= SCREEN_HEIGHT) {
		return false;
	}
}

void Paddle::DrawPivot() {
	DrawCircleV(pos, 3.0f, RED);
}