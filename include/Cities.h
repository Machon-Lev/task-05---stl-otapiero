#pragma once
#include <vector>
#include <string>
#include "NearbyCity.h"
#include <functional>
#include "DataExtractor.h"
#include <unordered_map>
#include <array>


class Cities
{

public:
    

    Cities();
    ~Cities();
    std::vector<NearbyCity> searchCities(const std::string& city_name, float radius, int distance_norm);
    bool isCity(const std::string& city_name);
	int countCitiesToTheNorth(std::string city_name, std::vector<NearbyCity> cities);
private:
    std::unordered_map<std::string, Coordinates> _cities;
	std::array<std::function<float(const Coordinates&, const Coordinates&)>, 3> distanceFunctions = {
			[](const Coordinates& c1, const Coordinates& c2) -> float {
				float dx = c2.getX() - c1.getX();
				float dy = c2.getY() - c1.getY();
				return std::sqrt(dx * dx + dy * dy);
			},
			[](const Coordinates& c1, const Coordinates& c2) -> float {
				float dx = std::abs(c2.getX() - c1.getX());
				float dy = std::abs(c2.getY() - c1.getY());
				return std::max(dx, dy);
			},
			[](const Coordinates& c1, const Coordinates& c2) -> float {
				float dx = std::abs(c2.getX() - c1.getX());
				float dy = std::abs(c2.getY() - c1.getY());
				return dx + dy;
			}
		};

};