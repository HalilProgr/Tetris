#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>

#include <vector>
#include <array>

enum class Command {
	Left,
	Up,
	Right,
	Down
};

/// <summary>
/// Класс - фигруа, выполняет:
/// 1) Движение
/// 2) Хранение цыета
/// 3) 
/// 
/// Дочеоние классы должны переопределить: Rotate и начальный _ofcet.
/// </summary>
class AbstractShape
{
public:
	enum class Stage {
		First,
		Second,
		Third,
		Fourth 
	};
	
	/// <summary>
	/// Конструктор, принимает начальное состояние фигуры.
	/// </summary>
	AbstractShape();
	virtual ~AbstractShape(){};

	/// <summary>
	/// Инициализирует фигуру, задаём цвет и координаты центар фигуры на карте.
	/// </summary>
	/// <returns></returns>
	virtual void init(sf::Color color, sf::Vector2i center);

	virtual void move(Command cm);
	virtual std::array<sf::Vector2i, 4> getCoordinates();
	virtual std::array<sf::Vector2i, 4> getCoordinatesNextStage();

	virtual sf::Color getColor() const { return _color; };
private:
	void changeStage();
protected:
	virtual std::array<sf::Vector2i, 4> getOffset(Stage) = 0;
private:
	sf::Color _color;
protected:
	sf::Vector2i _center;

	Stage _stage;
	Stage _nextStage;
};

