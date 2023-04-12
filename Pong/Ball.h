#pragma once
#include "common.h"
#include "raylib.h"
#include "Drawable.h"
#include "Paddle.h"

class Ball : public Drawable {
public:
	Ball(float radius, Color fillColor, Paddle& p1, Paddle& p2);
	void Init();
	void Reset();
	void Update();

private:
	static const float DEFAULT_SPEED;
	static const float SPEED_MULTI;
	static const float SPEED_TRANSFER_RATIO;

	Paddle& paddle1;
	Paddle& paddle2;

	float radius;
	float speed;
	float angle;

	Vector2 direction;
	Vector2 pos;

	Color fillColor;
	void Draw();
	void Move();

	float computeStartingAngle(bool goRight);
	void computeDirectionVector();
	void collideWithWall();
	bool checkCollisionWall();
	void collideWithPaddle(Paddle& paddle);
	bool checkCollisionPaddle(Paddle& paddle);

	void reflectAngleHorizontal();
	void reflectAngleVertical();
	float computeNormalAngle(float originalAngle);
	int getAngleQuadrant();
};