#pragma once
#include "common.h"
#include "Vector2.h"
#include "Drawable.h"
#include "Paddle.h"
#include "Pausable.h"

class Ball : public Drawable, public Pausable {
public:
	static float DEFAULT_RADIUS;
	static const float DEFAULT_SPEED;
	Ball(float radius, Color fillColor, Paddle& p1, Paddle& p2);
	void Init();
	void Reset();
	void Update();
	void SetDirection(Vector2 vector);
	void SetSpeed(float newSpeed);
	int IsOutOfBounds();

private:
	static const int PADDLE_DISABLED_FRAMES;
	static const float SPEED_MULTI;
	static const float SPEED_TRANSFER_RATIO;

	Paddle& paddle1;
	Paddle& paddle2;

	float radius;
	float speed;

	Vector2 direction;
	Vector2 pos;

	Color fillColor;
	void Draw();
	void Move();

	Vector2 computeStartingDirection(bool goRight);
	void collideWithWall();
	bool checkCollisionWall();
	void collideWithPaddle(Paddle& paddle);
	bool checkCollisionPaddle(const Paddle& paddle);
};