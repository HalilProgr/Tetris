#pragma once

#include "data/DiscreptionModel.h"

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/VertexArray.hpp>

class ViewMap: public sf::Drawable, public sf::Transformable
{
public:
	explicit ViewMap(Size sizeWindow);

	void Init(DiscreptionModel disc);

	void Update();

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void CreateTitle(int x, int y, sf::Color color);

	sf::Color GetColorTitle(int codetitle);

private:
	std::span<int> _map;

	Size _sizeMap;
	Size _sizeWindow;

    sf::VertexArray _vertices;

	sf::Vector2f _tileSize;
};

