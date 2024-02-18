#pragma once

#include "ModelMap.h"

#include "AbstractShape.h"
#include "interfaces/IView.h"
#include "Factory/ShapeFactory.h"
#include "data/DiscreptionModel.h"
#include "data/Command.h"

#include <SFML/System/Clock.hpp>

#include <list>
#include <memory>

class Model
{
public:
	Model(Size sizeMap);

	void Update(Command cmnd);

	void AddView(IView* view);

	DiscreptionModel GetConfig();
private:
	IdShape RandomIdShape();
	sf::Color RandomColor();

	std::shared_ptr<AbstractShape> CreateShape();

	void UpdateViews();
private:
	std::list<IView*> _views;

	ModelMap _map;
	ShapeFactory _factory;

	std::shared_ptr<AbstractShape> _actualShape;
};