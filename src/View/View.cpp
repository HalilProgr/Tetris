#include "View.h"

View::View(sf::Vector2f sizeWindow, std::string title) :
    _window(sf::VideoMode(sizeWindow.x, sizeWindow.y), title),
    _vmap(sizeWindow)
{}

void View::update()
{
    _vmap.update();

    _window.clear();
    _window.draw(_vmap);
    _window.display();
}

void View::init(ConfigModel conf)
{
    _vmap.init(conf);
}

bool View::isOpen() const
{
    return _window.isOpen();
}

sf::RenderWindow& View::getWindow()
{
    return _window;
}
