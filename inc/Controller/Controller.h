#pragma once

#include "view/View.h"
#include "model/Model.h"

#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window.hpp>

#include <cstdlib>

/// @brief 
class Controller
{
public:
	Controller();

	void Init(Model* ptr_model, View* view);

	void Start();

	void Update();

private:
	Model* _model; 
	View* _view;
	
	sf::Clock _clock; 

	sf::Time _interval;
	sf::Time _oldTime;
};

