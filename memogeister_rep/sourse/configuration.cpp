#include "../include/configuration.h"
#include<iostream>
Configuration::Configuration(World& world) : world(world)
{}


void Configuration::proceed()
{
    switch (currentLevel)
    {
    case Level::Level1:
        currentLevel = Level::Level2;
        break;
    case Level::Level2:
        currentLevel = Level::Level3;
        break;
    case Level::Level3:
        currentLevel = Level::Level4;
        break;
    default:
        break;
    }
}

void Configuration::loadPlayer(sf::RenderWindow& window)
{
    Player player(world, window);
}

void Configuration::loadLevel1(sf::RenderWindow& window)
{
    loadPlayer(window);

    for (int i = 0; i < 2;i++)
    {
        spawnPlant(window);
    }

    spawnGhost(window, Ghost::GhostType::Ghost1);
}

void Configuration::loadLevel2(sf::RenderWindow& window)
{

    for (int i = 0; i < 5;i++)
    {
        spawnPlant(window);
    }

    spawnGhost(window, Ghost::GhostType::Ghost2);

}

void Configuration::loadLevel3(sf::RenderWindow& window)
{
    for (int i = 0; i < 7;i++)
    {
        spawnPlant(window);
    }

    spawnGhost(window, Ghost::GhostType::Ghost3);

}
void Configuration::loadLevel4(sf::RenderWindow& window)
{
    for (int i = 0; i < 10;i++)
    {
        spawnPlant(window);
    }

    spawnGhost(window, Ghost::GhostType::Sister);

}
void Configuration::spawnPlant(sf::RenderWindow& window)
{
    Plant plant(world, window);
}

void Configuration::spawnGhost(sf::RenderWindow& window, Ghost::GhostType type)
{
    Ghost ghost(world, window, type);
    std::cout << "spawned";
}
