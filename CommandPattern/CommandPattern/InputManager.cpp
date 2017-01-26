#include "stdafx.h"
#include "InputManager.h"

InputManager::InputManager(Player* player):
m_left(new Left(player)),
m_right(new Right(player)),
m_up(new Up(player)),
m_down(new Down(player)),
m_macroLeft(new MacroCommand()),
m_macroRight(new MacroCommand()),
m_macroUp(new MacroCommand()),
m_macroDown(new MacroCommand())
{
	for (int i = 0; i < 6; i++)
	{
		m_macroLeft->add(m_left);
		m_macroRight->add(m_right);
		m_macroUp->add(m_up);
		m_macroDown->add(m_down);
	}
}

InputManager::~InputManager()
{
	delete m_left;
	m_left = nullptr;
	delete m_right;
	m_right = nullptr;
	delete m_up;
	m_up = nullptr;
	delete m_macroLeft;
	m_macroLeft = nullptr;
	delete m_macroRight;
	m_macroRight = nullptr;
	delete m_macroUp;
	m_macroUp = nullptr;
	delete m_macroDown;
	m_macroDown = nullptr;
}

void InputManager::ProcessInput()
{
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0)
	{
		switch (e.type)
		{
		case SDL_KEYDOWN:

			switch (e.key.keysym.sym)
			{
			case SDLK_a:
				m_left->command();
				break;

			case SDLK_d:
				m_right->command();
				break;

			case SDLK_w:
				m_up->command();
				break;

			case SDLK_s:
				m_down->command();
				break;

			case SDLK_1:
				m_macroLeft->excecute();
				break;

			case SDLK_2:
				m_macroRight->excecute();
				break;

			case SDLK_3:
				m_macroUp->excecute();
				break;

			case SDLK_4:
				m_macroDown->excecute();
				break;
			}

		default:
			break;
		}
	}
}