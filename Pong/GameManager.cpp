#include "GameManager.h"

const Vector2 GameManager::PADDLE_DIMENSIONS = Vector2{ 15, 100 };
const float GameManager::PADDLE_OFFSET = 50.0f;
const float GameManager::BALL_RADIUS = 5.0f;

GameManager::GameManager(Paddle& p1, Paddle& p2, Ball& ball) :
	p1(p1),
	p2(p2),
	ball(ball) {
	canvas = Canvas::GetInstance();
}

GameManager* GameManager::GetInstance() {
	if (instancePtr == NULL) {
		float midY = (SCREEN_HEIGHT / 2.0f) - (PADDLE_DIMENSIONS.y / 2.0f);
		Paddle paddle1 = Paddle{ 1, PADDLE_DIMENSIONS, Vector2{PADDLE_OFFSET, midY}, WHITE };
		Paddle paddle2 = Paddle{ 2, PADDLE_DIMENSIONS, Vector2{SCREEN_WIDTH - (PADDLE_OFFSET + PADDLE_DIMENSIONS.x), midY}, WHITE };
		Ball b = Ball{ BALL_RADIUS, RED, paddle1, paddle2 };
		instancePtr = new GameManager(paddle1, paddle2, b);
	}
	return instancePtr;
}

void GameManager::Start() {
	Init();
	Run();
}

void GameManager::Init() {
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
	p1.Update();
	p2.Update();
	ball.Update();

	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
		ball.Reset();
	}

	EndDrawing();
}

void GameManager::Quit() {
	CloseWindow();
}

GameManager::~GameManager() {
	if (canvas != NULL) {
		delete(canvas);
	}
}