#include "Drawable.h"

Drawable::Drawable() :
	isHidden(false) {};

void Drawable::Hide() {
	isHidden = true;
}

void Drawable::Show() {
	isHidden = false;
}