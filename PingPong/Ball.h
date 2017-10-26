#pragma once
#include "Entity.h"
class Ball : public Entity
{
public:
	Ball();
	virtual void update(const double &delta);
	double velX;
	double velY;
	void handleCollision(Entity &entity);
	~Ball();
};

