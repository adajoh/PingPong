#pragma once
#include "Entity.h"
class Player :public Entity
{
public:
	Player();
	virtual void update(const double &delta);
	~Player();
private:
	const double speed = 500;
};