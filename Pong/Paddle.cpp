#include "Paddle.h"

const float Paddle::DEFAULT_SPEED = 10.0f;

Paddle::Paddle(Vector2& dimensions, Vector2& pos, Color fillColor) :
	dimensions(dimensions),
	pos(pos),
	fillColor(fillColor) {
	speed = DEFAULT_SPEED;
};

float Paddle::GetHeight() {
	return pos.x;
}

float Paddle::GetWidth() {
	return pos.y;
}

const Vector2& Paddle::GetPos() {
	return pos;
}

void Paddle::SetPos(Vector2& newPos) {
	pos = newPos;
}

void Paddle::Draw() {
	DrawRectangleV(pos, dimensions, fillColor);
}

const Color& Paddle::GetFillColor() {
	return fillColor;
}

void Paddle::MoveDown() {
	if (IsInBoundsBottom()) {
		pos.y = pos.y + DEFAULT_SPEED;
	}
	else {
		pos.y = SCREEN_HEIGHT - dimensions.y;
	}
}

void Paddle::MoveUp() {
	if (IsInBoundsTop()) {
		pos.y = pos.y - DEFAULT_SPEED;
	}
	else {
		pos.y = 0;
	}
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