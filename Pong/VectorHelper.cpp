#include "VectorHelper.h"

namespace VectorHelper {
	Vector2 ReflectVertical(const Vector2& vector) {
		return Vector2{ vector.x * -1.0f, vector.y };
	}

	Vector2 ReflectHorizontal(const Vector2& vector) {
		return Vector2{ vector.x, vector.y * -1.0f };
	}

	Vector2 Normalize(const Vector2& vector) {
		float x = vector.x;
		float y = vector.y;

		float vLength = sqrtf(x * x + y * y);
		float xNormal = x / vLength;
		float yNormal = y / vLength;

		return Vector2{ xNormal, yNormal };
	}
}