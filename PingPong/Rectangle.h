#pragma once
class Rectangle
{
public:
	Rectangle();
	double x;
	double y;
	double w;
	double h;
	bool colliding(const Rectangle &target);
	~Rectangle();
};

