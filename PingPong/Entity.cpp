#include "Entity.h"


Entity::Entity(int x, int y, int width, int height)
{
	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;
}

const void Entity::render(SDL_Renderer * renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	renderRect.x = rect.x;
	renderRect.y = rect.y;
	renderRect.w = rect.w;
	renderRect.h = rect.h;
	SDL_RenderFillRect(renderer, &renderRect);
}

Rectangle &Entity::getRect()
{
	return rect;
}

Entity::~Entity()
{
}

bool Entity::clampHor()
{
	if (rect.y <0)
	{
		rect.y = 0;
		return true;
	}

	if (rect.y+rect.h>480)
	{
		rect.y = 480-rect.h;
		return true;
	}

	return false;
}
