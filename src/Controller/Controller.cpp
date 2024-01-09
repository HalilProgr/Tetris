#include "Controller.h"

Controller::Controller() :
	_model(nullptr),
	_view(nullptr)
{
	_interval = sf::seconds(0.05f);
}

void Controller::init(Model* ptr_model, View* view)
{
	_model = ptr_model;
	_view = view;
}

void Controller::start()
{
	_oldTime = _clock.restart();
}


void Controller::update()
{
	sf::Event event;
	while ((_view->getWindow()).pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			_view->getWindow().close();
			return;
		}

		if (event.type == sf::Event::KeyPressed)
		{
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D)))
				_model->update(Command::Right);
			else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A)))
				_model->update(Command::Left);
			else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W)))
				_model->update(Command::Up);
			else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S)))
				_model->update(Command::Down);
		}
	}

	if (_clock.getElapsedTime() - _oldTime > _interval)
	{
		_model->update(Command::Down);
		_oldTime = _clock.restart();
	}
}