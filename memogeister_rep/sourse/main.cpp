#include <SFML/Window.hpp>
#include "../include/game.h"

int main()
{
    ResourceManager::initializeTextures();

    Game game;
    game.run();

    return 0;
}