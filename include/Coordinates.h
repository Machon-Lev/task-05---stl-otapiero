#pragma once
#include <string>
class Coordinates
{
	float y_cord;
	float x_cord;
	public:
		Coordinates() : y_cord(0), x_cord(0) {}

		float getX() const { return x_cord; }
		float getY() const { return y_cord; }
		void setX(float x) { x_cord = x; }
		void setY(float y) { y_cord = y; }
};