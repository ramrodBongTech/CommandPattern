#pragma once

#include "InputManager.h"

class Game
{
public:
	Game();														// Constructor
	~Game();													// Standard destructor

	void					update();							// Standard update
	void					render();							// Standard render

private:
	SDL_Window*				m_window = nullptr;
	SDL_Renderer*			m_renderer = nullptr;
	Player*					m_player = nullptr;
	InputManager			m_inputManager;						// Object to control user input
};

