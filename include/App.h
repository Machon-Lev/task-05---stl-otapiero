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



};