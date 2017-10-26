#pragma once

#include <SDL.h>
#include "Rectangle.h"

class Entity
{
public:
	Entity(int x,int y,int width,int height);
	const void render(SDL_Renderer *renderer);
	virtual void update(const double &delta) = 0;
	Rectangle& getRect();
	~Entity();
protected:
	Rectangle rect;
	bool clampHor();
private:
	SDL_Rect renderRect;
};