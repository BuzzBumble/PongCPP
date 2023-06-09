#pragma once
#include "common.h"
#include "Paddle.h"
#include "Ball.h"
#include "Canvas.h"
#include "Client.h"

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

	int p1Score;
	int p2Score;
	Paddle& p1;
	Paddle& p2;
	Ball& ball;
	Canvas* canvas;
	State gameState;
	Client& client;

	void handleInputs();
	void updateServer();
};