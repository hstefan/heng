#include "vector.hpp"
#include "transform.hpp"
#include <iostream>

int main(int argc, char** argv)
{
	base::vec2 v = {{1,2}};
	base::vec2 v1 = {{-1,2}};
	base::vec2 v2 = {{-1,-2}};
	base::vec2 v3 = {{1, -2}};
	std::cout << v << "is at the " << (int)base::quadrant(v) << " quadrant" << std::endl;
	std::cout << v1 << "is at the " << (int)base::quadrant(v1) << " quadrant" << std::endl;
	std::cout << v1 << "is at the " << (int)base::quadrant(v2) << " quadrant" << std::endl;
	std::cout << v2 << "is at the " << (int)base::quadrant(v3) << " quadrant" << std::endl;
	
	
	base::vec2 c = RotateClockwise(v, 45);
	base::vec2 d = RotateAntiClockwise(c, 45);

	std::cout << base::unit(v) << std::endl;
	std::cout << base::unit(c) << std::endl;
	std::cout << base::unit(d) << std::endl;

	std::cout << base::dot(v,c) << std::endl;
	std::cout << norm(v)*norm(c)*std::cos(45.f) << std::endl;

	std::cout << base::dot(d,c) << std::endl;
	std::cout << norm(v)*norm(c)*std::cos(45.f) << std::endl;

	std::cin.get();
}