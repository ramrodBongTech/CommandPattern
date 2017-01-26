#include "stdafx.h"
#include "Game.h"

Game::Game():
m_player(new Player),
m_inputManager(InputManager(m_player))
{
	m_window = SDL_CreateWindow("Command Pattern", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1200, 600, SDL_WINDOW_SHOWN);
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
}

Game::~Game()
{
}

//** calls update on all game entities*/
void Game::update()
{
	m_inputManager.ProcessInput();
}

//** calls render on all game entities*/
void Game::render()
{
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_renderer);

	m_player->draw(m_renderer);

	SDL_RenderPresent(m_renderer);
}
