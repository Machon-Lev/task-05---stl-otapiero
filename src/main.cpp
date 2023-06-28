#include <iostream>
#include <exception>
#include "App.h"

int main()
{
	try
	{
		App app;
		app.run();
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}
