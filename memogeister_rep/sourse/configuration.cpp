#include "../include/configuration.h"
#include<iostream>
Configuration::Configuration(World& world) : world(world)
{}


void Configuration::loadPlayer(sf::RenderWindow& window)
{
    Player player(world, window);
}

void Configuration::spawnPlant(sf::RenderWindow& window)
{
    Plant plant(world, window);
}

void Configuration::spawnGhost(sf::RenderWindow& window)
{
    Ghost ghost(world, window);
    std::cout << "spawned";
}
