#include "vector.hpp"
#include <iostream>

int main(int argc, char** argv)
{
	base::vec2 v = {{1,2}};

	std::cout << base::unit(v) << std::endl;

	std::cin.get();
}