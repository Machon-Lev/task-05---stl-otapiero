#include "App.h"
#include <iostream>
#include <City.h>
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
		std::cin >> selected_city_name;
		if (_cities.isCity(selected_city_name))
		{
			throw std::runtime_error("ERROR: \"" + selected_city_name + "\" isn't found in the city list. Please try again.");
		}
		std::string radius_str;
		std::cout << "Please enter radius (with line break after it):" << std::endl;
		std::cin >> radius_str;
		float radius = std::stod(radius_str);
		if (radius <= 0)
		{
			throw std::runtime_error("ERROR: Radius must be a positive number. Please try again.");
		}
		int distance_norm = 0;
		std::cout << "Please enter the wanted norm (0 – L2, Euclidean distance, 1 – Linf, Chebyshev distance, 2 – L1, Manhattan distance):" << std::endl;
		std::cin >> distance_norm;
		if (distance_norm < 0 || distance_norm > 2)
		{
			throw std::runtime_error("ERROR: Norm must be 0, 1 or 2. Please try again.");
		}



	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
		run();
	}

}
