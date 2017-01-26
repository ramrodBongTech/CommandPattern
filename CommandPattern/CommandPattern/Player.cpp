#include "stdafx.h"
#include "Player.h"

Player::Player() :
m_rect(Rect(Point2D(600, 300), Size2D(50, 50))),
m_colour(Colour(0, 255, 0))
{}

Player::~Player(){}

void Player::draw(SDL_Renderer* renderer)
{ 
	SDL_SetRenderDrawColor(renderer, m_colour.r, m_colour.g, m_colour.b, m_colour.a);
	SDL_Rect sr;
	sr.h = (int)m_rect.size.h;
	sr.w = (int)m_rect.size.w;
	sr.x = (int)m_rect.pos.x;
	sr.y = (int)m_rect.pos.y;
	SDL_RenderFillRect(renderer, &sr);
}

void Player::setPosition(Point2D pos){ m_rect.pos = pos; }

void Player::moveLeft()
{
	m_rect.pos.x -= 10;
}

void Player::moveRight()
{
	m_rect.pos.x += 10;
}

void Player::moveUp()
{
	m_rect.pos.y -= 10;
}

void Player::moveDown()
{
	m_rect.pos.y += 10;
}