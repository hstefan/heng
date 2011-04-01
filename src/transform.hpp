#ifndef HSTEFAN_TRANSFORM_HPP
#define HSTEFAN_TRANSFORM_HPP

#include "vector.hpp"
#include "matrix.hpp"
#include <cmath>

namespace base
{
	inline vec2 RotateClockwise(const vec2& vec, float angle)
	{
		mat2d m = { 
			std::cos(angle) , std::sin(angle), 
		   -std::sin(angle), std::cos(angle) 
		};

		return m*vec;
	}

	inline vec2 RotateAntiClockwise(const vec2& vec, float angle)
	{
		mat2d m = {
			std::cos(angle), -std::sin(angle), 
			std::sin(angle),  std::cos(angle)
		};

		return m*vec;
	}
}

#endif