#include "Map.h"

#include <iostream>

Map::Map(int width, int hight):_width(width), _hight(hight), _colorShape(0)
{
	size_t size = size_t(width) * size_t(hight);

	_map = new int[size_t(width) * size_t(hight)];

	for (size_t i = 0; i < size; i++)
		_map[i] = 0;
}

Map::~Map() {
	delete[] _map;
}

void Map::addShape(std::array<sf::Vector2i, 4> coordsShape, sf::Color color)
{
	_position = coordsShape;

	if (color == sf::Color::Black)
		_colorShape = 0;
	else if (color == sf::Color::White)
		_colorShape = 1;
	else if (color == sf::Color::Red)
		_colorShape = 2;
	else if (color == sf::Color::Green)
		_colorShape = 3;
	else if (color == sf::Color::Blue)
		_colorShape = 4;
	else if (color == sf::Color::Yellow)
		_colorShape = 5;
	else if (color == sf::Color::Magenta)
		_colorShape = 6;
	else if (color == sf::Color::Cyan)
		_colorShape = 7;


	for (auto& cor : _position) {
		if (cor.x < 0 || cor.x > _width - 1 || cor.y < 0) continue;

		_map[cor.y * _width + cor.x] = _colorShape;
	}
}


void Map::updateMap(std::array<sf::Vector2i, 4> newCoordShape)
{
	for (auto& cor : _position) {
		if (cor.x < 0 || cor.x > _width - 1 || cor.y < 0) continue;

		_map[cor.y * _width + cor.x] = 0;
	}

	_position = newCoordShape;

	for (auto& cor : _position) {
		if (cor.x < 0 || cor.x > _width - 1 || cor.y < 0) continue;

		_map[cor.y * _width + cor.x] = _colorShape;
	}
}

bool Map::checkPosition(std::array<sf::Vector2i, 4> newCoords)
{
	for (auto& cor : _position) {
		if (cor.x < 0 || cor.x > _width - 1 || cor.y < 0) continue;

		_map[cor.y * _width + cor.x] = 0;
	}

	bool state = true;

	for (auto& coor : newCoords) {
		if (coor.x < 0
			|| (coor.x > (_width - 1))
			|| (coor.y > (_hight - 1))
			|| (coor.y < 0))
		{
			state = false;
			break;
		}

		if (_map[coor.y * _width + coor.x] != 0) {
			state = false;
			break;
		}
	}

	
	for (auto& cor : _position) {
		if (cor.x < 0 || cor.x > _width - 1 || cor.y < 0) continue;
		_map[cor.y * _width + cor.x] = _colorShape;
	}
	
	return state;
}

int Map::checkTetris()
{
	/// _____________
	/// |* * * * * *| 
	/// |1 1 1 1 1 0|
	/// |1 0 1 0 0 0| <--- конец
	/// |1 1 1 1 1 1|
	/// |1 1 1 1 1 1| <--- начало
	/// `````````````

	// к примеру начало в y = 19, конец в y = 17, линий -  2.
	// значит надо на 2 линии сместить то что находить над "начало" и 2 линии добавить  сверху.


	int startLine = -1;
	int endLine = -1;
	bool firstOccurrence = false;
	// Логика прохождения по линиям и нахождения начала и конца "тетриса"
	for (int y = _hight - 1; y > 0; y--) {
		if (!firstOccurrence)
		{
			if (cheakLine(y))
			{
				firstOccurrence = true;
				startLine = y;
			}
		}
		else if (!cheakLine(y))
			{
				endLine = y;
				break;
			}
	}

	// если startLine == endLine, то выходим
	// то есть ни одной линии не найдено.
	if (startLine == endLine) return 0;

	int gap = startLine - endLine;

	// пройти по всем линиям от endLine до вершины и сместить их на gap.
	for (int y = endLine; y > 0; y--)
	{
		for (int x = 0; x < _width - 1; x++)
		{
			_map[(y + gap) * _width + x] = _map[y * _width + x];
		}
	}

	// добавить сверху gap линий.
	for (int y = 0; y < gap; y++)
	{
		for (int x = 0; x < _width - 1; x++)
		{
			_map[y * _width + x] = 0;
		}
	}

	return gap;
}

const int* Map::getMap()
{
	return _map;
}

bool Map::cheakLine(int y)
{
	for (int x = 0; x < _width; x++) {
		if (_map[y * _width + x] == 0) return false;
	}

	return true;
}
