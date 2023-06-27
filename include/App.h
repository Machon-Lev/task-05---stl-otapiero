#pragma once
#include <unordered_map>
#include "Coordinates.h"
#include "DataExtractor.h"
#include <functional>
#include "Cities.h"
class App
{
	private:
		Cities _cities;

	public:
		App();
		~App();
		void run();
		void printNearbyCities(std::string city_name, float radius, int distance_norm);



};