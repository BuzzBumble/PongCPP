#pragma once

class Drawable {
public:
	Drawable() {};
	virtual ~Drawable() {};
	virtual void Draw() = 0;
	virtual void Update() = 0;
};