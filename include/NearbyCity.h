#pragma once
#include "Coordinates.h"
class NearbyCity
{
private:
	std::string _name;
	Coordinates _coordinates;
	float _distance;
public:
	NearbyCity(std::string name, Coordinates coordinates,float distance);
	~NearbyCity();
	std::string getName() const;
	Coordinates getCoordinates() const;
	float getDistance() const;
};