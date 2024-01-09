#pragma once

#include "AbstractShape.h" 
class Jblock : public AbstractShape
{
protected:
	std::array<sf::Vector2i, 4> getOffset(Stage stage) override
	{
		std::array<sf::Vector2i, 4> offset;

		switch (stage)
		{
		case AbstractShape::Stage::First:
			offset[0] = { -1,-1 };
			offset[1] = { -1, 0 };
			offset[2] = { 0, 0 };
			offset[3] = { 1, 0 };
			break;
		case AbstractShape::Stage::Second:
			offset[0] = { 1,-1 };
			offset[1] = { 0,-1 };
			offset[2] = { 0, 0 };
			offset[3] = { 0, 1 };
			break;
		case AbstractShape::Stage::Third:
			offset[0] = { 1,1 };
			offset[1] = { 1,0 };
			offset[2] = { 0,0 };
			offset[3] = { -1,0 };
			break;
		case AbstractShape::Stage::Fourth:
			offset[0] = { -1, 1 };
			offset[1] = { 0, 1 };
			offset[2] = { 0, 0 };
			offset[3] = { 0,-1 };
			break;
		default:
			break;
		}

		return offset;
	};
};

