#pragma once

#include "AbstractShape.h"

#include "SFML/System/Vector2.hpp"

/// <summary>
///  ласс реализующий логику пол€ игрового пространства,
/// _map - данные пол€ карты.
/// ƒанный класс реализует только карту, добавление фигуры к карте,
/// проверка новых координат фигуры на свободное поле или нет.
/// </summary>
class Map
{
public:
	/// <summary>
	///  онструток карты.
	/// </summary>
	/// <param name="width"> ол-во плиток по ширине</param>
	/// <param name="hight"> ол-во плиток по высоте</param>
	Map(int width, int hight);
	~Map();

	void addShape(std::array<sf::Vector2i, 4> coordsShape, sf::Color color);

	void updateMap(std::array<sf::Vector2i, 4> coordsShape);
	bool checkPosition(std::array<sf::Vector2i, 4> newCoords);
	int  checkTetris();

	const int* getMap();
private:
	bool cheakLine(int y);
private:
	std::array<sf::Vector2i, 4> _position; // “екущее положение фигуры
	
	int _colorShape; // цвет актуальной фигуры

	int _width; // кол-во плиток по ширина
	int _hight; // кол-во плиток по высота

	int* _map; // карта
};