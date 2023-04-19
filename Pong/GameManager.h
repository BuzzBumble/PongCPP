#pragma once
#include "raylib.h"
#include "common.h"
#include "Paddle.h"
#include "Ball.h"
#include "Canvas.h"

class GameManager {
private:
	static const Vector2 PADDLE_DIMENSIONS;
	static const float PADDLE_OFFSET;
	static const float BALL_RADIUS;
	static GameManager* instancePtr;
	GameManager(Paddle& p1, Paddle& p2, Ball& ball);
	GameManager() = delete;
	~GameManager();

	Paddle& p1;
	Paddle& p2;
	Ball& ball;
	Canvas* canvas;

public:
	GameManager(const GameManager& gameMgrObj) = delete;

	static GameManager* GetInstance();

	void Start();
	void Init();
	void Run();
	void Update();
	void Quit();
};