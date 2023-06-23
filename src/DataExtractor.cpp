#include "DataExtractor.h"
#include <iostream>
#include <fstream>

DataExtractor::DataExtractor(const std::string& path) : path(path)
{
	extractData();
}

DataExtractor::~DataExtractor()
{

}

std::unordered_map<std::string, Coordinates> DataExtractor::getCities()
{
	return cities;
}

void DataExtractor::extractData()
{
	std::ifstream file(path, std::ios::in);
	if (!file.is_open())
	{
		throw std::exception("File not found");
	}
	std::string city_name_line;
	std::string city_cords_line;
	while (std::getline(file, city_name_line))
	{
		if (!std::getline(file, city_cords_line))
		{
			throw std::runtime_error("File not formatted correctly");
		}
		std::string city_name = city_name_line;
		size_t separator_pos = city_cords_line.find(" - ");
		if (separator_pos == std::string::npos)
		{
			throw std::runtime_error("Invalid city coordinates format");
		}
		std::string city_x_cord = city_cords_line.substr(0, separator_pos);
		std::string city_y_cord = city_cords_line.substr(separator_pos + 3); // Skip the " - " separator
		Coordinates city_coordinates;
		city_coordinates.setY(std::stoi(city_y_cord));
		city_coordinates.setX(std::stoi(city_x_cord));
		auto result = cities.insert(std::make_pair(city_name, city_coordinates));
		if (!result.second)
		{
			throw std::runtime_error("Duplicate city name");
		}

	}
}


