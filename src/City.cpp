#include "City.h"

City::City(std::string name, Coordinates coordinates)
{
	this->_name = name;
	this->_coordinates = coordinates;
}

City::~City()
{
}

std::string City::get_name() const
{
	return _name;
}

Coordinates City::get_coordinates() const
{
	return _coordinates;
}
