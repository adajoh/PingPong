#include "Player.h"



Player::Player() : Entity(600,200,10,100)
{
}

void Player::update(const double & delta)
{
	const Uint8 *state = SDL_GetKeyboardState(NULL);

	if (state[SDL_SCANCODE_UP]) {
		rect.y -= speed*delta;
	}
	if (state[SDL_SCANCODE_DOWN]) {
		rect.y += speed*delta;
	}

	clampHor();
}


Player::~Player()
{
}
