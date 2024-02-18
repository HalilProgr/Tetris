#pragma once

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

#include <array>

struct DiscreptionShape
{
    sf::Color color;
    std::array<sf::Vector2i, 4> coordinates;
};