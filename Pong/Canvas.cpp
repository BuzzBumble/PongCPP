#include "Canvas.h"

Canvas* Canvas::getInstance() {
	if (instancePtr == NULL) {
		instancePtr = new Canvas();
	}
	return instancePtr;
}