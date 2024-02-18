#pragma once

#include "view/View.h"
#include "model/Model.h"
#include "controller/Controller.h"

class Game
{
public:
    explicit Game();
	void Run();
private:
    View view;
    Model model;
    Controller controller;
};

