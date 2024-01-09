#include "Game.h"

Game::Game():
	view(sf::Vector2f{ 400,600 }, "Tetris"),
	model(3, sf::Vector2i(20, 40))
{
    view.init(model.getConfig());
	controller.init(&model, &view);

    model.addView(&view);
}

void Game::run()
{
    controller.start();

    while (view.isOpen())
    {
        controller.update();
    }
}
