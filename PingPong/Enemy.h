#pragma once
#include "Entity.h"
#include "Ball.h"

class Enemy :public Entity
{
public:
	Enemy(Ball &ball);
	virtual void update(const double &delta);
	~Enemy();
private:
	Ball &ball;
	const double SPEED = 300;
};

