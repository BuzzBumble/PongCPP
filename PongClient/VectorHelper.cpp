#include "VectorHelper.h"


Vector2 VectorHelper::ReflectVertical(const Vector2& vector) {
	return Vector2{ vector.x * -1.0f, vector.y };
}

Vector2 VectorHelper::ReflectHorizontal(const Vector2& vector) {
	return Vector2{ vector.x, vector.y * -1.0f };
}

Vector2 VectorHelper::Normalize(const Vector2& vector) {
	float x = vector.x;
	float y = vector.y;

	float vLength = sqrtf(x * x + y * y);
	float xNormal = x / vLength;
	float yNormal = y / vLength;

	return Vector2{ xNormal, yNormal };
}

Vector2 VectorHelper::Subtract(const Vector2& v2, const Vector2& v1) {
	return Vector2{ v2.x - v1.x, v2.y - v1.y };
}