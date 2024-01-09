#include "Model.h"
#include "Iblock.h"
#include "Tblock.h"
#include "Oblock.h"

#include <iostream>

void operator+=(std::array<sf::Vector2i, 4>& cor, sf::Vector2i lf);

Model::Model(int sizeQueue, sf::Vector2i sizeMap):
	_map(sizeMap.x, sizeMap.y),
	_sizeMap(sizeMap)
{
	srand(time(NULL));

	_factory.add<Iblock>(IdShape::Iblock);
	_factory.add<Tblock>(IdShape::Tblock);
	_factory.add<Oblock>(IdShape::Oblock);

	_actualShape = createShape();
	_map.addShape(_actualShape->getCoordinates(), _actualShape->getColor());
}

void Model::update(Command cm)
{
	std::array<sf::Vector2i, 4> cor;

	switch (cm)
	{
	case Command::Left:
		cor = _actualShape->getCoordinates();
		cor += sf::Vector2i(-1, 0);
		break;
	case Command::Up:
		cor = _actualShape->getCoordinatesNextStage();
		break;
	case Command::Right:
		cor = _actualShape->getCoordinates();
		cor += sf::Vector2i(1, 0);
		break;
	case Command::Down:
		cor = _actualShape->getCoordinates();
		cor += sf::Vector2i(0, 1);
		break;
	default:
		break;
	}

	if (_map.checkPosition(cor))
	{
		_actualShape->move(cm);
		_map.updateMap(_actualShape->getCoordinates());
	}
	else
	{
		if (cm == Command::Down)
		{
			_actualShape = createShape();
			_map.checkTetris();
			_map.addShape(_actualShape->getCoordinates(), _actualShape->getColor());
		}
	}

	updateViews();
}

void Model::addView(AbstratView* view)
{
	_views.push_back(view);
}

ConfigModel Model::getConfig()
{
	return ConfigModel(_map.getMap(), _sizeMap.x, _sizeMap.y);
}

IdShape Model::randomIdShape()
{
	return static_cast<IdShape>(std::rand()%_factory.size());
}

sf::Color Model::randomColor()
{
	sf::Color color;
	int i = std::rand() % 7 + 1;
	if (i == 1)
		color = sf::Color::White;
	else if(i == 2)
		color = sf::Color::Red;
	else if (i == 3)
		color = sf::Color::Green;
	else if (i == 4)
		color = sf::Color::Blue;
	else if (i == 5)
		color = sf::Color::Yellow;
	else if (i == 6)
		color = sf::Color::Magenta;
	else if (i == 7)
		color = sf::Color::Cyan;

	return color;
}

AbstractShape* Model::createShape()
{
	AbstractShape* result = _factory.create(randomIdShape());
	result->init(randomColor(), sf::Vector2i(_sizeMap.x/2, 3));
	return result;
}

void Model::updateViews()
{
	for (auto& view : _views)
		view->update();
}

void operator+=(std::array<sf::Vector2i, 4>& cor, sf::Vector2i lf)
{
	for (auto& x : cor) x += lf;
};