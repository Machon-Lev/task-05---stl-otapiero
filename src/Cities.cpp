#include "Cities.h"
#include <iostream>
#include <algorithm>

Cities::Cities()
{
    try 
    {
        _cities = DataExtractor("data.txt").getCities();

    }
    catch (std::exception& e)
    {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

}

Cities::~Cities()
{
}

std::vector<NearbyCity> Cities::searchCities(const std::string& city_name, float radius, int distance_norm) {
    std::vector<NearbyCity> nearby_cities;

    auto city_it = _cities.find(city_name);
    if (city_it == _cities.end()) {
        std::cout << "City not found!" << std::endl;
        return nearby_cities;
    }

    const Coordinates& target_city_coordinates = city_it->second;

    std::transform(
        _cities.begin(),
        _cities.end(),
        std::back_inserter(nearby_cities),
        [&](const auto& city_pair) {
            const Coordinates& city_coordinates = city_pair.second;
            if (city_pair.first == city_name) {
                return NearbyCity("", Coordinates(), 0.0f); // Default City object for false cases
            }
            if (std::abs(city_coordinates.getX() - target_city_coordinates.getX()) > radius ||
                std::abs(city_coordinates.getY() - target_city_coordinates.getY()) > radius) {
                return NearbyCity("", Coordinates(), 0.0f); // Default City object for false cases
            }
            float distance = distanceFunctions[distance_norm](target_city_coordinates, city_coordinates);
            if (distance <= radius) {
                return NearbyCity(city_pair.first, city_coordinates, distance);
            }
            return NearbyCity("", Coordinates(), 0.0f); // Default City object for false cases
        }
    );

    nearby_cities.erase(
        std::remove_if(
            nearby_cities.begin(),
            nearby_cities.end(),
            [](const NearbyCity& city) {
                return city.getName().empty();
            }
        ),
        nearby_cities.end()
    );

    std::sort(
        nearby_cities.begin(),
        nearby_cities.end(),
        [](const NearbyCity& city1, const NearbyCity& city2) {
            return city1.getDistance() < city2.getDistance();
        }
    );

    return nearby_cities;
}


bool Cities::isCity(const std::string& city_name)
{
	return _cities.find(city_name) == _cities.end();
}

int Cities::countCitiesToTheNorth(std::string city_name, std::vector<NearbyCity> cities)
{
    try {
        auto city_it = _cities.find(city_name);
        if (city_it == _cities.end()) {
			std::cout << "City not found!" << std::endl;
			return 0;
		}

		const Coordinates& target_city_coordinates = city_it->second;

       return std::count_if(
            cities.begin(),
            cities.end(),
            [&](const NearbyCity& city) {
                return city.getCoordinates().getY() > target_city_coordinates.getY();
            }
        );

   }
	catch (std::exception& e)
	{
        std::cout << "Exception caught: " << e.what() << std::endl;
        throw e;
    
    }
}

