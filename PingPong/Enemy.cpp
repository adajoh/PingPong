#include "Enemy.h"



Enemy::Enemy(Ball &ball) : ball(ball),Entity(40, 200, 10, 100)
{
}

void Enemy::update(const double & delta)
{
	if (ball.getRect().y>rect.y)
	{
		rect.y += SPEED*delta;
	}

	if (ball.getRect().y<rect.y)
	{
		rect.y -= SPEED*delta;
	}

	clampHor();
}


Enemy::~Enemy()
{
}
