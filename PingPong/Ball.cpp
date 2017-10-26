#include "Ball.h"



Ball::Ball() : Entity(200, 100, 10, 10)
{
	velX = 200;
	velY = 300;
}

void Ball::update(const double & delta)
{
	rect.x += velX*delta;
	rect.y += velY*delta;

	if (clampHor())
	{
		velY *= -1;
	}
}


void Ball::handleCollision(Entity & entity)
{
	if (rect.colliding(entity.getRect()))
	{
		velX *= -1;
	}
}

Ball::~Ball()
{
}
