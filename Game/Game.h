#include <iostream>
#include <SDL.h>
#include <GL/glew.h>
using namespace std;

class Game
{

public:
	Game(string windowTitle, int width, int height);
	void initGame();
	void execGame();
	void exitGame();

private:
	string windowTitle;
	int windowWidth;
	int windowHeight;
	SDL_Window *gameWindow;
	SDL_GLContext glContext;
	SDL_Event sdlEvent;
	bool endingGame;
};

