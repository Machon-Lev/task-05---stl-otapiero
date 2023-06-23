#include "Cities.h"
#include <iostream>
#include <algorithm>

Cities::Cities()
{
	_cities = DataExtractor("..//resources//data.txt").getCities();

}

Cities::~Cities()
{
}

std::vector<City> Cities::searchCities(const std::string& city_name, float radius,int distance_norm) {
	std::vector<City> nearby_cities;


    if (_cities.find(city_name) == _cities.end()) {
        std::cout << "City not found!" << std::endl;
        return nearby_cities;
    }
    //TODO: Implement this function
    const Coordinates& target_city_coordinates = _cities[city_name];

    return nearby_cities;
}

bool Cities::isCity(const std::string& city_name)
{
	return _cities.find(city_name) == _cities.end();
}

