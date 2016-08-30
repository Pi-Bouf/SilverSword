#include <iostream>
#include <SDL.h>
#include "Game.h"

using namespace std;

int main(int argc, char *args[])
{

	cout << "    _______  ___  ___     __   __  _______  ______    _______  _     _  _______  ______    ______  " << endl;
	cout << "   |       ||   ||   |   |  | |  ||       ||    _ |  |       || | _ | ||       ||    _ |  |      | " << endl;
	cout << "   |  _____||   ||   |   |  |_|  ||    ___||   | ||  |  _____|| || || ||   _   ||   | ||  |  _    |" << endl;
	cout << "   | |_____ |   ||   |   |       ||   |___ |   |_||_ | |_____ |       ||  | |  ||   |_||_ | | |   |" << endl;
	cout << "   |_____  ||   ||   |___|       ||    ___||    __  ||_____  ||       ||  |_|  ||    __  || |_|   |" << endl;
	cout << "    _____| ||   ||       ||     | |   |___ |   |  | | _____| ||   _   ||       ||   |  | ||       |" << endl;
	cout << "   |_______||___||_______| |___|  |_______||___|  |_||_______||__| |__||_______||___|  |_||______| " << endl;

	// Instanciate a new game
	Game newGame("Test", 800, 600);
	newGame.initGame();
	newGame.execGame();

	return 0;
}