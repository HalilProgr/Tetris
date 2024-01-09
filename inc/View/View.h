#pragma once

#include "AbstratView.h"
#include "ConfigModel.h"

#include "ViewMap.h"

#include "SFML/Graphics/RenderWindow.hpp"

class View : public AbstratView
{
public:
	View(sf::Vector2f sizeWindow, std::string title);

	void update() override;
	void init(ConfigModel conf);
	bool isOpen() const;

	sf::RenderWindow& getWindow();
private:
	sf::Vector2f _sizeWindow;

	sf::RenderWindow _window;

	ViewMap _vmap;
};

