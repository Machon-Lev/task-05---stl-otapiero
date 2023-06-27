#pragma once
#include <string>
#include <vector>
#include "NearbyCity.h"
#include <unordered_map>

class DataExtractor
{
	// this class is used to extract data from a file and return a data structure
	private:
		std::string path;
		std::unordered_map<std::string, Coordinates> cities;
public:
	DataExtractor(const std::string& path);
	~DataExtractor();
	std::unordered_map<std::string, Coordinates> getCities();
	void extractData();

};