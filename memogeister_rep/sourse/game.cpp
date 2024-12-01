#include "../include/game.h"

Game::Game() : gameState(GameState::StartScreen), configuration(world)
{
	initWindow();
    configuration.currentLevel = Configuration::Level::Level1;
    configuration.loadPlayer(window);
    
    const sf::Texture& textureBack = ResourceManager::textures.at(ResourceManager::Texture::BackgroundImage);
    background.setTexture(textureBack);

    const sf::Texture& textureMain = ResourceManager::textures.at(ResourceManager::Texture::MainMenu);
    mainMenu.setTexture(textureMain);


    const sf::Texture& textureGhost1 = ResourceManager::textures.at(ResourceManager::Texture::Ghost1Full);
    ghost1Full.setTexture(textureGhost1);

    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureBackSize = textureBack.getSize();
    sf::Vector2u textureMainSize = textureMain.getSize();
    sf::Vector2u textureGhost1Size = textureGhost1.getSize();
    background.setScale(
        static_cast<float>(windowSize.x) / textureBackSize.x,
        static_cast<float>(windowSize.y) / textureBackSize.y
    );

    mainMenu.setScale(
        static_cast<float>(windowSize.x) / textureMainSize.x,
        static_cast<float>(windowSize.y) / textureMainSize.y
    );

    ghost1Full.setOrigin(textureGhost1Size.x/2.f, textureGhost1Size.y/2.f);
    ghost1Full.setPosition(window.getSize().x/2, window.getSize().y/2);
}

void Game::pollEvents()
{
    while (window.pollEvent(sfmlEvent))
    {
        switch (sfmlEvent.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            if (sfmlEvent.key.code == sf::Keyboard::Escape)
            {
                gameState = GameState::Exiting;
            }
            break;
        default:
            break;
        }
    }
}

void Game::pollEventsStartScreen()
{
    while (window.pollEvent(sfmlEvent))
    {
        switch (sfmlEvent.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            if (sfmlEvent.key.code == sf::Keyboard::Space)
            {
                gameState = GameState::Leveling;
            }
            else if (sfmlEvent.key.code == sf::Keyboard::Escape)
            {
                gameState = GameState::Exiting;
            }
            break;

        default:
            break;
        }
    }
}


const bool Game::running() const
{
    return window.isOpen();
}

void Game::initWindow()
{
    videoMode = sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);


    window.create(videoMode, "Memogeister", sf::Style::Fullscreen | sf::Style::Close);
    window.setFramerateLimit(60);
 

}

void Game::handleLevel()
{
    switch(configuration.currentLevel)
    {
    case Configuration::Level::Level1:
        for (int i = 0; i < 5;i++)
        {
            configuration.spawnPlant(window);
        }

        configuration.spawnGhost(window);

        break;

    }

    gameState = GameState::Playing;
}
void Game::render()
{
    window.clear(sf::Color::Black);
    window.draw(background);
    window.draw(world);
    window.display();
}

void Game::handlePlaying(float deltaTime)
{
    update(deltaTime);
    pollEvents();
    render();
}

void Game::handleStartScreen()
{
    pollEventsStartScreen();
    window.clear(sf::Color::Black);
    window.draw(mainMenu);
    window.display();
}

void Game::handleCutScene()
{
    window.clear(sf::Color::Black);
    window.draw(ghost1Full);
    window.display();
}

void Game::update(float deltaTime)
{
    world.update(deltaTime);

    if (world.isCutScene)
    {
        gameState = GameState::Cutscene;
    }
}

void Game::run() {
    sf::Clock clock;

    while (running()) {
        float deltaTime = clock.restart().asSeconds();

        switch (gameState) {
        case GameState::StartScreen:
            handleStartScreen();
            break;
        case GameState::Leveling:
            handleLevel();
            break;
        case GameState::Playing:
            handlePlaying(deltaTime);
            break;
        case GameState::Cutscene:
            handleCutScene();
            break;
        case GameState::Exiting:
            window.close();
            break;
        }
    }
}
