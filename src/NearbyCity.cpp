#include "NearbyCity.h"

NearbyCity::NearbyCity(std::string name, Coordinates coordinates,float distance)
{
	this->_name = name;
	this->_coordinates = coordinates;
	this->_distance = distance;
}

NearbyCity::~NearbyCity()
{
}

std::string NearbyCity::getName() const
{
	return _name;
}

Coordinates NearbyCity::getCoordinates() const
{
	return _coordinates;
}

float NearbyCity::getDistance() const
{
	return _distance;
}
