// Game.cpp : Defines the entry point for the application.
//

#include "Game.h"

using namespace std;

int main(void)
{
	GameManager* gameManager = GameManager::GetInstance();
	gameManager->Start();

	return 0;
}