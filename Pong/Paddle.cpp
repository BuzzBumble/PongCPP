#include "Paddle.h"

Paddle::Paddle(Vector2& dimensions, Vector2& pos, Color borderColor, Color fillColor) :
	dimensions(dimensions),
	pos(pos),
	borderColor(borderColor),
	fillColor(fillColor) {};

float Paddle::getHeight() {
	return pos.x;
}

float Paddle::getWidth() {
	return pos.y;
}

const Vector2& Paddle::getPos() {
	return pos;
}

void Paddle::setPos(Vector2& newPos) {
	pos = newPos;
}

void Paddle::Draw() {
	DrawRectangleV(pos, dimensions, fillColor);
}

const Color& Paddle::getBorderColor() {
	return borderColor;
}

const Color& Paddle::getFillColor() {
	return fillColor;
}