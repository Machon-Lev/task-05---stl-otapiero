#pragma once
#include <string>
class Coordinates
{
	int y_cord;
	int x_cord;
	public:
		Coordinates() : y_cord(0), x_cord(0) {}

		int getX() const { return x_cord; }
		int getY() const { return y_cord; }
		void setX(int x) { x_cord = x; }
		void setY(int y) { y_cord = y; }
};