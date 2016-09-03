#include "Input.h"

Input::Input()
{
	m_x = 0;
	m_y = 0;
	m_xRel = 0;
	m_yRel = 0;
	ending = false;

	for (int i = 0; i < SDL_NUM_SCANCODES; i++)
	{
		m_keys[i] = false;
	}

	for (int j = 0; j < 8; j++)
	{
		m_mouse[j] = false;
	}

}

void Input::updateEvent()
{
	m_xRel = 0;
	m_yRel = 0;

	while (SDL_PollEvent(&sdlEvent))
	{
		switch (sdlEvent.type)
		{
		case SDL_KEYDOWN:
			m_keys[sdlEvent.key.keysym.scancode] = true;
			break;
		case SDL_KEYUP:
			m_keys[sdlEvent.key.keysym.scancode] = false;
			break;
		case SDL_WINDOWEVENT:
			if (sdlEvent.window.event == SDL_WINDOWEVENT_CLOSE)
				ending = true;
			break;
		case SDL_MOUSEBUTTONDOWN:
			m_mouse[sdlEvent.button.button] = true;
			break;
		case SDL_MOUSEBUTTONUP:
			m_mouse[sdlEvent.button.button] = false;
			break;
		case SDL_MOUSEMOTION:
			m_x = sdlEvent.motion.x;
			m_y = sdlEvent.motion.y;

			m_xRel = sdlEvent.motion.xrel;
			m_yRel = sdlEvent.motion.yrel;
		}
	}
}

void Input::cursorDisplay(bool state)
{
	if (state)
		SDL_ShowCursor(SDL_ENABLE);

	else
		SDL_ShowCursor(SDL_DISABLE);
}

void Input::cursorCapture(bool state)
{
	if (state)
	{
		SDL_SetRelativeMouseMode(SDL_TRUE);
	}
	else {
		SDL_SetRelativeMouseMode(SDL_FALSE);
	}
}

bool Input::getKey(const SDL_Scancode key) const
{
	return m_keys[key];
}

bool Input::getMouse(const Uint8 button) const
{
	return m_mouse[button];
}

bool Input::movedMouse()
{
	if ((m_xRel == 0) && (m_yRel == 0))
	{
		return false;
	}
	else {
		return true;
	}
}

bool Input::getEnding()
{
	return ending;
}

int Input::getX() const
{
	return m_x;
}

int Input::getY() const
{
	return m_y;
}

int Input::getXRel() const
{
	return m_xRel;
}

int Input::getYRel() const
{
	return m_yRel;
}

Input::~Input()
{
}
