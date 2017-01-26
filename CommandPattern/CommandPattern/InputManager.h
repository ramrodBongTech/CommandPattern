#pragma once

#include "Command.h"
#include "Player.h"

class InputManager
{
public:
	InputManager(Player* player);												// Standard Constructor
	~InputManager();											// Standard Destructor

	void ProcessInput();										// Genereate events

private:
	Left* m_left;
	Right* m_right;
	Up* m_up;
	Down* m_down;
	
	MacroCommand* m_macroLeft;
	MacroCommand* m_macroRight;
	MacroCommand* m_macroUp;
	MacroCommand* m_macroDown;
};

