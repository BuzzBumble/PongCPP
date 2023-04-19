#pragma once
#include "raylib.h"
#include "common.h"
#include "Paddle.h"
#include "Ball.h"
#include "Canvas.h"

class GameManager {
public:
	enum State {
		BeforeStart,
		Playing,
		Paused,
		GameOver
	};

	GameManager(Paddle& p1, Paddle& p2, Ball& ball);
	void Start();
	void Init();
	void Run();
	void Update();
	void Quit();
	void Pause();
	void Unpause();

private:
	GameManager() = delete;

	Paddle& p1;
	Paddle& p2;
	Ball& ball;
	Canvas* canvas;
	State gameState;

	void handleInputs();
};