#pragma once
#include "Coordinates.h"
class City
{
private:
	std::string _name;
	Coordinates _coordinates;
public:
	City(std::string name, Coordinates coordinates);
	~City();
	std::string get_name() const;
	Coordinates get_coordinates() const;
};