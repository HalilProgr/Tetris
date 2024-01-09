#pragma once
#include "AbstractShape.h"
class Oblock : public AbstractShape
{
protected:
	std::array<sf::Vector2i, 4> getOffset(Stage) override
	{
		std::array<sf::Vector2i, 4> offset;

		offset[0] = { 1,0 };
		offset[1] = { 1,-1 };
		offset[2] = { 0,0 };
		offset[3] = { 0,-1 };

		return offset;
	};
};