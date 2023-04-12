#pragma once
#include "common.h"
#include "raylib.h"
#include "Drawable.h"
#include "Paddle.h"

class Ball : public Drawable {
private:
	static const float DEFAULT_SPEED;
	float radius;
	float speed;
	float angle;

	Vector2 direction;
	Vector2 pos;
	
	Color fillColor;

	float ComputeStartingAngle(bool goRight);
	void ComputeDirectionVector();
	void CollideWithWall();
	bool CheckCollisionWall();

public:
	Ball(float radius, Color fillColor);
	void Init();
	void Draw();
	void Move();
	void Reset();

	void CollideWithPaddle(Paddle& paddle);

	bool isCollidingWithPaddle(Paddle& paddle);

};