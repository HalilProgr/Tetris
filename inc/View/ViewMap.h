#pragma once

#include "ConfigModel.h"

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/VertexArray.hpp>

/// <summary>
/// класс - поле.
/// </summary>
class ViewMap: public sf::Drawable, public sf::Transformable
{
public:
	ViewMap(sf::Vector2f sizeWindow);
	void init(ConfigModel conf);
	void update();
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void createTitle(int x, int y, sf::Color color);
	sf::Color getColorTitle(int codetitle);
private:
	const int* _map;

    sf::VertexArray _vertices;

	sf::Vector2f _tileSize;
	sf::Vector2i _sizeWindow;

	int _width;
	int _height;
};

