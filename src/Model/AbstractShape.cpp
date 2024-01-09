#include "AbstractShape.h"

AbstractShape::AbstractShape() : _color(0), _center(sf::Vector2i(0, 0)) {
	_stage = Stage::First;
	_nextStage = Stage::Second;
}

void AbstractShape::init(sf::Color color, sf::Vector2i center)
{
	_color = color;
	_center = center;
}

void AbstractShape::move(Command cm)
{
	switch (cm)
	{
	case Command::Left:
		_center.x -= 1;
		break;
	case Command::Up:
		changeStage();
		break;
	case Command::Right:
		_center.x += 1;
		break;
	case Command::Down:
		_center.y += 1;
		break;
	default:
		break;
	}
}

std::array<sf::Vector2i, 4> AbstractShape::getCoordinates()
{
	std::array<sf::Vector2i, 4> result = getOffset(_stage);;

	for (int i = 0; i < result.size(); i++)
		result[i] = _center + result[i];

	return result;
}

void AbstractShape::changeStage()
{
	switch (_stage)
	{
	case AbstractShape::Stage::First:
		_stage = AbstractShape::Stage::Second;
		_nextStage = AbstractShape::Stage::Third;
		break;
	case AbstractShape::Stage::Second:
		_stage = AbstractShape::Stage::Third;
		_nextStage = AbstractShape::Stage::Fourth;
		break;
	case AbstractShape::Stage::Third:
		_stage = AbstractShape::Stage::Fourth;
		_nextStage = AbstractShape::Stage::First;
		break;
	case AbstractShape::Stage::Fourth:
		_stage = AbstractShape::Stage::First;
		_nextStage = AbstractShape::Stage::Second;
		break;
	default:
		break;
	}
}

std::array<sf::Vector2i, 4> AbstractShape::getCoordinatesNextStage() {
	std::array<sf::Vector2i, 4> result = getOffset(_nextStage);

	for (int i = 0; i < result.size(); i++)
		result[i] = _center + result[i];

	return result;
}