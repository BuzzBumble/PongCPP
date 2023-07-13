#include "Paddle.h"

const float Paddle::DEFAULT_SPEED = 10.0f;
const float Paddle::TARGET_FRAME_TIME = 1.0f / GLOBAL_FRAME_RATE;
Vector2 Paddle::DEFAULT_DIMENSIONS = Vector2{ 15, 100 };
float Paddle::DEFAULT_OFFSET = 50.0f;

Paddle::Paddle(int id, Vector2 dimensions, Vector2 pos, Color fillColor) :
	id(id),
	dimensions(dimensions),
	pos(pos),
	fillColor(fillColor),
	direction(Direction::STILL),
	isCollidable(true),
	frameCounter(0.0f)
{
	speed = DEFAULT_SPEED;
	rect = Rectangle{ pos.x, pos.y, dimensions.x, dimensions.y };

	topBottomPadding = dimensions.x / 5.0f;
	leftRightPadding = dimensions.y / 10.0f;
	sideSectionSize = (dimensions.y - leftRightPadding * 2) / 3.0f;
};

float Paddle::GetHeight() const {
	return pos.x;
}

float Paddle::GetWidth() const {
	return pos.y;
}

const Rectangle& Paddle::GetRect() const {
	return rect;
}

const Vector2& Paddle::GetPos() const {
	return pos;
}

void Paddle::SetPos(const Vector2& newPos) {
	pos = newPos;
}

void Paddle::SetDirection(const Direction dir) {
	direction = dir;
}

Paddle::Direction Paddle::GetDirection() const {
	return direction;
}

void Paddle::Draw() {
	if (!isHidden) {
		DrawRectangleV(pos, dimensions, fillColor);
	}
}

const Color& Paddle::GetFillColor() {
	return fillColor;
}

void Paddle::Update() {
	if (!paused) {
		updateRectangle();
		if (!isCollidable) {
			tickDisabledCollision();
		}
		if (IsKeyDown(KEY_DOWN)) {
			MoveDown();
		}
		else if (IsKeyDown(KEY_UP)) {
			MoveUp();
		}
		else {
			SetDirection(Direction::STILL);
		}
	}
}

void Paddle::MoveDown() {
	if (IsInBoundsBottom()) {
		pos.y = pos.y + DEFAULT_SPEED;
		SetDirection(Direction::DOWN);
	}
	else {
		pos.y = SCREEN_HEIGHT - dimensions.y;
		SetDirection(Direction::STILL);
	}
}

void Paddle::MoveUp() {
	if (IsInBoundsTop()) {
		pos.y = pos.y - DEFAULT_SPEED;
		SetDirection(Direction::UP);
	}
	else {
		pos.y = GAME_TOP;
		SetDirection(Direction::STILL);
	}
}

bool Paddle::IsCollidable() const {
	return isCollidable;
}

void Paddle::DisableCollision(int frames) {
	frameCounter = frames;
	isCollidable = false;
}

void Paddle::tickDisabledCollision() {
	frameCounter -= GetFrameTime() / TARGET_FRAME_TIME;
	if (frameCounter < 0) {
		isCollidable = true;
	}
}

void Paddle::updateRectangle() {
	rect.x = pos.x;
	rect.y = pos.y;
	rect.width = dimensions.x;
	rect.height = dimensions.y;
}

bool Paddle::IsInBoundsTop() {
	if (pos.y <= GAME_TOP) {
		return false;
	}
}

bool Paddle::IsInBoundsBottom() {
	if (pos.y + dimensions.y >= SCREEN_HEIGHT) {
		return false;
	}
}

void Paddle::DrawPivot() {
	DrawCircleV(pos, 3.0f, RED);
}