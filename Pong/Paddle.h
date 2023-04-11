#include "raylib.h"
#include "Drawable.h"

class Paddle : public Drawable {
private:
	Vector2& pos;
	Vector2& dimensions;

	Color borderColor;
	Color fillColor;

public:
	Paddle(Vector2& dimensions, Vector2& pos, Color borderColor, Color fillColor);

	float getHeight();
	float getWidth();

	const Vector2& getPos();

	void setPos(Vector2& newPos);

	void Draw();

	const Color& getBorderColor();
	const Color& getFillColor();
};