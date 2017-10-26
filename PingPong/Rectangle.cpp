#include "Rectangle.h"



Rectangle::Rectangle()
{
}

bool Rectangle::colliding(const Rectangle &target)
{
	return x < target.x + target.w && x + w > target.x && y < target.y + target.h && y + h > target.y;
}


Rectangle::~Rectangle()
{
}
