#pragma once

#include "SDL.h"
#include "BasicTypes.h"

class Player
{
public:
	Player();																		// Constructor
	~Player();																		// Standard Destructor

	void					draw(SDL_Renderer* renderer);							// Standard Draw

	void					setPosition(Point2D pos);								// Sets the position of the player

	void					moveLeft();												// Moves the left a single tile
	void					moveRight();											// Moves the right a single tile
	void					moveUp();
	void					moveDown();

private:
	Rect					m_rect;													// The rectangle object we draw
	Colour					m_colour;												// The colour of the rectangle

};