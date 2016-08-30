#include <iostream>
#include <SDL.h>
#include "Game.h"

using namespace std;

int main(int argc, char *args[])
{
	Game newGame("Test", 800, 600);
	newGame.initGame();
	newGame.execGame();

	return 0;
}