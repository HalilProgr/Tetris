#pragma once

#include "View.h"
#include "Model.h"

#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window.hpp>

#include <cstdlib>

/// <summary>
/// Класс контроллер, отвечает:
/// 1) за обработку нажатий клавишь пользователя
/// 2) вызов обновления положения фигуры.
/// </summary>
class Controller
{
public:
	Controller();

	void init(Model* ptr_model, View* view);
	void start();
	void update();

private:
	Model* _model; // модель с которой проиходит взаимодействие.
	View* _view;
	sf::Clock _clock; //

	sf::Time _interval;
	sf::Time _oldTime;
};

