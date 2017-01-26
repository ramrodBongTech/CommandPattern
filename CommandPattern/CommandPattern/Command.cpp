#include "stdafx.h"
#include "Command.h"

Command::Command(){}

Command::~Command()
{
	m_player = nullptr;
}

void Command::command(){}

Left::Left(Player* player)
{
	m_player = player;
}

void Left::command()
{
	m_player->moveLeft();
}

Right::Right(Player* player)
{
	m_player = player;
}

void Right::command()
{
	m_player->moveRight();
}

Up::Up(Player* player)
{
	m_player = player;
}

void Up::command()
{
	m_player->moveUp();
}

Down::Down(Player* player)
{
	m_player = player;
}

void Down::command()
{ 
	m_player->moveDown(); 
}

MacroCommand::MacroCommand(){}

MacroCommand::~MacroCommand()
{
	while (!m_commands.empty())
	{
		delete m_commands.front();
		m_commands.pop_front();
	}
}

void MacroCommand::add(Command* command){ m_commands.push_back(command); }

void MacroCommand::remove(Command* command){ m_commands.remove(command); }

void MacroCommand::excecute()
{
	for (std::list<Command*>::iterator _it = m_commands.begin(); _it != m_commands.end(); ++_it)
	{
		Command* _c = *(_it);
		_c->command();
	}
}

void MacroCommand::command(){}