#include "ViewMap.h"

ViewMap::ViewMap(sf::Vector2f sizeWindow):
    _width(0),
    _height(0),
    _sizeWindow(sizeWindow),
    _map(nullptr)
{}

void ViewMap::init(ConfigModel conf)
{
    _width = conf.width;
    _height = conf.hight;

    _vertices.setPrimitiveType(sf::Triangles);
    _vertices.resize(_width * _height * 6);

    _tileSize.x = _sizeWindow.x / _width;
    _tileSize.y = _sizeWindow.y / _height;

    if (conf.ptr_map != nullptr && _map == nullptr)
        _map = conf.ptr_map;
}

void ViewMap::update()
{
    if (_map == nullptr) return;
    
    int x = 0;
    int y = 0;

    int _mapSize = _width * _height;

    for (int i = 0; i < _mapSize; i++)
    {
        sf::Color color = getColorTitle(_map[i]);
        createTitle(x, y, color);

        if (x < _width - 1)
            x++;
        else
            x = 0, y++;
    }
}


void ViewMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(_vertices, states);
}

void ViewMap::createTitle(int x, int y, sf::Color color)
{
    sf::Vertex* triangles = &_vertices[(x + y * _width) * 6];

    triangles[0].position = sf::Vector2f(x * _tileSize.x, y * _tileSize.y);
    triangles[1].position = sf::Vector2f((x + 1) * _tileSize.x, y * _tileSize.y);
    triangles[2].position = sf::Vector2f(x * _tileSize.x, (y + 1) * _tileSize.y);
    triangles[3].position = sf::Vector2f(x * _tileSize.x, (y + 1) * _tileSize.y);
    triangles[4].position = sf::Vector2f((x + 1) * _tileSize.x, y * _tileSize.y);
    triangles[5].position = sf::Vector2f((x + 1) * _tileSize.x, (y + 1) * _tileSize.y);

    for (int i = 0; i < 6; i++)
        triangles[i].color = color;
}

sf::Color ViewMap::getColorTitle(int codetitle)
{
    sf::Color color;

    switch (codetitle)
    {
    case 0:
        color = sf::Color::Black;
        break;
    case 1:
        color = sf::Color::White;
        break;
    case 2:
        color = sf::Color::Red;
        break;
    case 3:
        color = sf::Color::Green;
        break;
    case 4:
        color = sf::Color::Blue;
        break;
    case 5:
        color = sf::Color::Yellow;
        break;
    case 6:
        color = sf::Color::Magenta;
        break;
    case 7:
        color = sf::Color::Cyan;
        break;
    default:
        color = sf::Color::Black;
        break;
    }
    return color;
}
