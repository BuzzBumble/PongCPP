#pragma once
#include "raylib.h"
#include "Drawable.h"
#include "common.h"

class Paddle : public Drawable {
private:
	static const float DEFAULT_SPEED;

	Vector2& pos;
	Vector2& dimensions;

	Color fillColor;

	float speed;

public:
	Paddle(Vector2& dimensions, Vector2& pos, Color fillColor);

	float GetHeight();
	float GetWidth();

	const Vector2& GetPos();
	void SetPos(Vector2& newPos);

	const Color& GetFillColor();

	void Draw();

	void MoveDown();
	void MoveUp();

	bool IsInBoundsTop();
	bool IsInBoundsBottom();

	void DrawPivot();
};