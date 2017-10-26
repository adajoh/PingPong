#pragma once

#include <SDL.h>
#include "Player.h"
#include "Enemy.h"
#include "Ball.h"

class PingPong
{
public:
	PingPong();
	void update(double delta);
	void render(SDL_Renderer *renderer);
	~PingPong();
private:
	Player player;
	Enemy enemy;
	Ball ball;

};