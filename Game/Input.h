#ifndef DEF_INPUT
#define DEF_INPUT
#include <SDL.h>
#include <iostream>

using namespace std;

class Input
{
public:
	Input();
	~Input();
	void updateEvent();
	void cursorDisplay(bool state);
	void cursorCapture(bool state);
	bool getKey(const SDL_Scancode key) const;
	bool getMouse(const Uint8 button) const;
	bool movedMouse();
	bool getEnding();//

	int getX() const;
	int getY() const;
	int getXRel() const;
	int getYRel() const;

private:
	SDL_Event sdlEvent;
	bool m_keys[SDL_NUM_SCANCODES];
	bool m_mouse[8];

	int m_x;
	int m_y;
	int m_xRel;
	int m_yRel;

	bool ending;

};
#endif