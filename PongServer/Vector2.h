#pragma once
#include <cmath>

class Vector2 {
public:
	float x;
	float y;

	Vector2 ReflectVertical();
	Vector2 ReflectHorizontal();

	Vector2 Normalize();
	Vector2 Subtract(const Vector2& v1);
};