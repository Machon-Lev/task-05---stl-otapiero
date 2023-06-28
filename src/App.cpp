#include "App.h"
#include <iostream>
#include <NearbyCity.h>
#include <Cities.h>

App::App()
{
}

App::~App()
{
}

void App::run()
{
	try
	{
		std::string selected_city_name;
		std::cout << "Please enter selected city name (with line break after it):" << std::endl;
		std::getline(std::cin, selected_city_name);
		if (selected_city_name == "0")
		{
			std::cout << "Bye" << std::endl;
			return;
		}
		if (_cities.isCity(selected_city_name))
		{
			throw std::invalid_argument("ERROR: \"" + selected_city_name + "\" isn't found in the city list. Please try again.");
		}
		std::string radius_str;
		std::cout << "Please enter radius (with line break after it):" << std::endl;
	    std::getline(std::cin, radius_str);
		float radius = std::stof(radius_str);
		if (radius <= 0)
		{
			throw std::invalid_argument("ERROR: Radius must be a positive number. Please try again.");
		}
		std::string distanceNormString;
		std::cout << "Please enter the wanted norm (0 - L2, Euclidean distance, 1 - Linf, Chebyshev distance, 2 - L1, Manhattan distance):" << std::endl;
		std::getline(std::cin, distanceNormString);
		int distance_norm = std::stoi(distanceNormString);
		if (distance_norm < 0 || distance_norm > 2)
		{
			throw std::invalid_argument("ERROR: Norm must be 0, 1 or 2. Please try again.");
		}
		printNearbyCities(selected_city_name, radius, distance_norm);
		run();
	}
	catch (const std::invalid_argument& ex)
	{
		std::cout << ex.what() << std::endl;
		run();
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

}

void App::printNearbyCities(std::string city_name, float radius, int distance_norm)
{
	try
	{
		auto nearby_cities = _cities.searchCities(city_name, radius, distance_norm);
		int countCitiesToTheNorth = _cities.countCitiesToTheNorth(city_name,nearby_cities);
		if (nearby_cities.empty())
		{
			std::cout << "No nearby cities found." << std::endl;
			return;
		}
		std::cout << "Search result:" << std::endl;
		std::cout << nearby_cities.size() << "  city/cities found in the given radius." << std::endl;
		std::cout << countCitiesToTheNorth << "  cities are to the north of the selected city." << std::endl;
		std::cout << "City list:" << std::endl;
		for (const auto& city : nearby_cities)
		{
			std::cout << city.getName() << std::endl;
		}
	}
	catch (const std::exception&)
	{
		std::cout << "ERROR: An error occurred while searching for nearby cities." << std::endl;
	}

}
