#include "Vector2.h"

Vector2 Vector2::ReflectVertical() {
	return Vector2{ x * -1.0f, y };
}

Vector2 Vector2::ReflectHorizontal() {
	return Vector2{ x, y * -1.0f };
}

Vector2 Vector2::Normalize() {
	float vLength = sqrtf(x * x + y * y);
	float xNormal = x / vLength;
	float yNormal = y / vLength;

	return Vector2{ xNormal, yNormal };
}

Vector2 Vector2::Subtract(const Vector2& v1) {
	return Vector2{ x - v1.x, y - v1.y };
}