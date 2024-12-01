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

	enum AllCutscenes
	{
		Ghost1,
		Ghost2,
		Ghost3,
		Sister
	};

	AllCutscenes currentCutscene;
	GameState gameState;



	sf::VideoMode videoMode;
	sf::RenderWindow window;
	sf::Event sfmlEvent;

	World world;
	Configuration configuration;
	
	sf::Sprite background, mainMenu, bg, ghost1Full, ghost2Full, ghost3Full, sisterFull, flowerTable, introPaper, gameOver;

	unsigned int width;
	unsigned int height;

public:

	Game();

	void initWindow();
	void initMainMenu();
	void handlePlaying(float deltaTime);
	void handleStartScreen();
	void handleCutScene();
	void handleGameOverScreen();

	void playCurrentScene();

	void pollEvents();
	void pollEventsStartScreen();
	void pollEventsCutscene();
	void pollEventsGameOver();

	void checkPlayer();
	void proceedToNextCutscene();

	const bool running() const;
	void run();

	void update(float deltaTime);
	void handleLevel();
	void render();
};

#endif 