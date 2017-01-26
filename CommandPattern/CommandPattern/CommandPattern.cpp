#include "stdafx.h"
#include <ctime>
#include "Game.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));

	Game game;

	while (true)
	{
		game.update();
		game.render();
	}

	return 0;
}

