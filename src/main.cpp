#include <iostream>
#include <exception>

int main()
{
	try
	{
		throw std::exception();
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}
