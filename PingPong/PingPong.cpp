#include "PingPong.h"


PingPong::PingPong() : player(),ball(),enemy(ball)
{

}

void PingPong::update(double delta)
{
	player.update(delta);
	enemy.update(delta);
	ball.update(delta);

	ball.handleCollision(player);
	ball.handleCollision(enemy);

	//Ball outside of screen
	if (ball.getRect().x>800)
	{
		ball.getRect().x = 640 / 2;
		ball.velX *= -1;
	}

	if (ball.getRect().x<-200)
	{
		ball.getRect().x = 640 / 2;
		ball.velX *= -1;
	}
}


void PingPong::render(SDL_Renderer *renderer)
{
	player.render(renderer);
	enemy.render(renderer);
	ball.render(renderer);
}

PingPong::~PingPong()
{
}

