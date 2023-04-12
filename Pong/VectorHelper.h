#pragma once
#include "raylib.h"
#include <cmath>

namespace VectorHelper {
	Vector2 ReflectVertical(const Vector2& vector);
	Vector2 ReflectHorizontal(const Vector2& vector);

	Vector2 Normalize(const Vector2& vector);
}