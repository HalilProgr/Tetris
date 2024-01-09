#pragma once

#include "View.h"
#include "Model.h"
#include "Controller.h"

/// Основная концепция:
/// У Model может быть много View.
/// У каждого View свой Controller
/// Для инициализации View используется структура ConfigModel

/// <summary>
/// Класс реализующий игру тетрис
/// </summary>
class Game
{
public:
    Game();
	void run();
private:
    View view;
    Model model;
    Controller controller;
};

