#pragma once
#include "raylib.h"
#include "Drawable.h"
#include "common.h"

class Paddle : public Drawable {
public:
	enum Direction {
		UP,
		DOWN,
		STILL
	};

	Paddle(int id, Vector2 dimensions, Vector2 pos, Color fillColor);

	void Update();

	float GetHeight() const;
	float GetWidth() const;

	const Rectangle& GetRect() const;

	const Vector2& GetPos() const;
	void SetPos(const Vector2& newPos);

	Direction GetDirection() const;
	void SetDirection(Direction dir);

	const Color& GetFillColor();

	void Draw();

	void MoveDown();
	void MoveUp();

	bool IsInBoundsTop();
	bool IsInBoundsBottom();

	void DrawPivot();

	float frameCounter;
	void DisableCollision(int frames);

	bool IsCollidable() const;

private:
	static const float DEFAULT_SPEED;

	static const float TARGET_FRAME_TIME;

	float topBottomPadding;
	float leftRightPadding;
	float sideSectionSize;

	int id;

	Vector2 pos;
	Vector2 dimensions;

	Rectangle rect;

	Color fillColor;

	float speed;

	Direction direction;

	bool isCollidable;

	void updateRectangle();
	void tickDisabledCollision();
};