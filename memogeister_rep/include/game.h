#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "world.h"
#include "configuration.h"

class Game
{
private:

	

	enum GameState
	{
		StartScreen,
		Leveling,
		Playing,
		Cutscene,
		GameOver,
		Exiting
	};


	GameState gameState;

	sf::VideoMode videoMode;
	sf::RenderWindow window;
	sf::Event sfmlEvent;

	World world;
	Configuration configuration;
	
	sf::Sprite background, mainMenu, ghost1Full;

	unsigned int width;
	unsigned int height;

public:

	Game();

	void initWindow();
	void initMainMenu();
	void handlePlaying(float deltaTime);
	void handleStartScreen();
	void handleCutScene();

	void pollEvents();
	void pollEventsStartScreen();

	const bool running() const;
	void run();

	void update(float deltaTime);
	void handleLevel();
	void render();
};

#endif 