#include "GameManager.h"

GameManager::GameManager(Paddle& p1, Paddle& p2, Ball& ball) :
	p1(p1),
	p2(p2),
	ball(ball),
	p1Score(0),
	p2Score(0),
	client(Client{ boost::asio::io_context{} })
{
	gameState = State::Paused;
	canvas = Canvas::GetInstance();
}

void GameManager::Start() {
	Init();
	Run();
}

void GameManager::Init() {
	client.ResolveReceiverEndpoint();
	std::cout << "Receiver Endpoint Resolved. Attempting Connection..." << std::endl;
	client.AttemptConnection();

	canvas->Init();
	ball.Init();
}

void GameManager::Run() {
	while (!WindowShouldClose()) {
		Update();
	}
	Quit();
}

void GameManager::Update() {
	BeginDrawing();
	canvas->Clear();
	if (IsKeyPressed(KEY_SPACE)) {
		if (gameState == Paused) {
			Unpause();
		}
		else {
			Pause();
		}
		
	}
	int ballCheck = ball.IsOutOfBounds();
	if (ballCheck) {
		if (ballCheck == 1) {
			p1Score++;
		}
		if (ballCheck == 2) {
			p2Score++;
		}
		ball.Reset();
		Pause();
	}

	canvas->DrawScore(p1Score, p2Score);
	p1.Update();
	p2.Update();
	ball.Update();
	handleInputs();

	EndDrawing();
}

void GameManager::handleInputs() {
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
		ball.Reset();
	}
}

void GameManager::Quit() {
	CloseWindow();
}

void GameManager::Pause() {
	gameState = Paused;
	p1.Pause();
	p2.Pause();
	ball.Pause();
}

void GameManager::Unpause() {
	gameState = Playing;
	p1.Unpause();
	p2.Unpause();
	ball.Unpause();
}

void GameManager::updateServer() {

}