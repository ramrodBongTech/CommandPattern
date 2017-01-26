#pragma once

#include <iostream>
#include <list>
#include "Player.h"

using namespace std;

class Command
{
public:
	Command();
	~Command();
	virtual void command();
protected:
	Player* m_player = nullptr;
};

class Left : public Command
{
public:
	Left(Player* player);
	void command();
};

class Right : public Command
{
public:
	Right(Player* player);
	void command();
};

class Up : public Command
{
public:
	Up(Player* player);
	void command();
};

class Down : public Command
{
public:
	Down(Player* player);
	void command();
};

class MacroCommand : public Command
{
public:
	MacroCommand();
	~MacroCommand();
	void add(Command* command);
	void remove(Command* command);
	void excecute();

	void command();

private:
	list<Command*> m_commands;
};