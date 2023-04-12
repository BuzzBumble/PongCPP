#pragma once
#include "common.h"
#include "raylib.h"
#include "Drawable.h"

class Ball {
private:
	static const float DEFAULT_SPEED;
	float radius;
	float speed;

	Vector2& direction;
	Vector2& pos;
	
	color fillColor;
public:
	Ball(float radius, Vector2& pos, Color fillColor);

	void Draw();

	void CollideWithPaddle(Paddle& paddle);
	bool CollideWithWallBottom();
	bool CollideWithWallTop();

	void Move();
};