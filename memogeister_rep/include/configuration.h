#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include"player.h"
#include"plant.h"
#include"potion.h"
#include"ghost.h"

class World;

class Configuration
{
private:
	World& world;

	


public:
	Configuration(World& world);

	enum class Level
	{
		Level1,
		Level2,
		Level3,
	};

	Level currentLevel;

	void loadPlayer(sf::RenderWindow& window);

	void spawnPlant(sf::RenderWindow& window);
	
	void spawnGhost(sf::RenderWindow& window);
	
};
#endif