#include "vector.hpp"
#include "transform.hpp"
#include <iostream>

int main(int argc, char** argv)
{
	base::vec2 v = {{1,2}};
	
	base::vec2 c = RotateClockwise(v, 45);

	std::cout << base::unit(v) << std::endl;
	std::cout << base::unit(c) << std::endl;

	std::cout << base::dot(v,c) << std::endl;
	std::cout << norm(v)*norm(c)*std::cos(45.f) << std::endl;

	std::cin.get();
}