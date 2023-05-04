#pragma once
#include <cmath>

namespace VectorHelper {
	Vector2 ReflectVertical(const Vector2& vector);
	Vector2 ReflectHorizontal(const Vector2& vector);

	Vector2 Normalize(const Vector2& vector);
	Vector2 Subtract(const Vector2& v2, const Vector2& v1);
}