#include "../include/game.h"

Game::Game() : gameState(GameState::StartScreen), currentCutscene(AllCutscenes::Ghost1), configuration(world)
{
	initWindow();
    configuration.currentLevel = Configuration::Level::Level1;
    //configuration.loadPlayer(window);
    
    const sf::Texture& textureBack = ResourceManager::textures.at(ResourceManager::Texture::BackgroundImage);
    background.setTexture(textureBack);

    const sf::Texture& textureMain = ResourceManager::textures.at(ResourceManager::Texture::MainMenu);
    mainMenu.setTexture(textureMain);

    const sf::Texture& textureBg = ResourceManager::textures.at(ResourceManager::Texture::bg);
    bg.setTexture(textureBg);

    const sf::Texture& textureGameOver = ResourceManager::textures.at(ResourceManager::Texture::gameOverScreen);
    gameOver.setTexture(textureGameOver);

    const sf::Texture& textureTable = ResourceManager::textures.at(ResourceManager::Texture::tableOfFlowers);
    flowerTable.setTexture(textureTable);

    const sf::Texture& textureIntroPaper = ResourceManager::textures.at(ResourceManager::Texture::introductionPaper);
    introPaper.setTexture(textureIntroPaper);

    const sf::Texture& textureGhost1 = ResourceManager::textures.at(ResourceManager::Texture::Ghost1Full);
    ghost1Full.setTexture(textureGhost1);
    const sf::Texture& textureGhost2 = ResourceManager::textures.at(ResourceManager::Texture::Ghost2Full);
    ghost2Full.setTexture(textureGhost2);
    const sf::Texture& textureGhost3 = ResourceManager::textures.at(ResourceManager::Texture::Ghost3Full);
    ghost3Full.setTexture(textureGhost3);
    const sf::Texture& textureSister = ResourceManager::textures.at(ResourceManager::Texture::SisterFull);
    sisterFull.setTexture(textureSister);

    sf::Vector2u windowSize = window.getSize();

    unsigned int x = windowSize.x;
    unsigned int y = windowSize.y;

    unsigned int halfX = x / 2;
    unsigned int halfY = y / 2;

    sf::Vector2u textureBackSize = textureBack.getSize();
    sf::Vector2u textureMainSize = textureMain.getSize();
    sf::Vector2u textureBgSize = textureBg.getSize();
    sf::Vector2u textureGmSize = textureGameOver.getSize();

    sf::Vector2u textureGhost1Size = textureGhost1.getSize();
    sf::Vector2u textureGhost2Size = textureGhost2.getSize();
    sf::Vector2u textureGhost3Size = textureGhost3.getSize();
    sf::Vector2u textureSisterSize = textureSister.getSize();

    background.setScale(
        static_cast<float>(x) / textureBackSize.x,
        static_cast<float>(y) / textureBackSize.y
    );

    mainMenu.setScale(
        static_cast<float>(x) / textureMainSize.x,
        static_cast<float>(y) / textureMainSize.y
    );
    bg.setScale(
        static_cast<float>(x) / textureMainSize.x,
        static_cast<float>(y) / textureMainSize.y
    );
    gameOver.setScale(
        static_cast<float>(x) / textureGmSize.x,
        static_cast<float>(y) / textureGmSize.y
    );


    ghost1Full.setOrigin(textureGhost1Size.x/2.f, textureGhost1Size.y/2.f);
    ghost2Full.setOrigin(textureGhost2Size.x / 2.f, textureGhost2Size.y / 2.f);
    ghost3Full.setOrigin(textureGhost3Size.x / 2.f, textureGhost3Size.y / 2.f);
    sisterFull.setOrigin(textureSisterSize.x / 2.f, textureSisterSize.y / 2.f);

    ghost1Full.setPosition(halfX, halfY);
    ghost2Full.setPosition(halfX, halfY);
    ghost3Full.setPosition(halfX, halfY);
    sisterFull.setPosition(halfX, halfY);

    flowerTable.setScale({ 0.25,0.25 });
    flowerTable.setOrigin(textureTable.getSize().x/2, textureTable.getSize().y / 2);
    flowerTable.setPosition(halfX, halfY + 300.f);

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
            if (sfmlEvent.key.code == sf::Keyboard::Space) {
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

void Game::pollEventsCutscene()
{
    static std::vector<int> playerInput; // Stores player inputs for the current cutscene 
    const auto& gatheredPlants = world.getPlayer()->getGatheredPlants(); // Correct order of plants

    while (window.pollEvent(sfmlEvent)) {
        switch (sfmlEvent.type) {
        case sf::Event::Closed:
            window.close();
            break;

        case sf::Event::KeyPressed:
            // Handle digit input (1-9)
            if (sfmlEvent.key.code >= sf::Keyboard::Num1 && sfmlEvent.key.code <= sf::Keyboard::Num9) {
                int digit = sfmlEvent.key.code - sf::Keyboard::Num1 + 1;
                playerInput.push_back(digit);

                // Check if the player has finished inputting all numbers
                if (playerInput.size() == gatheredPlants.size()) {
                    // Validate player input against gathered plants
                    bool isCorrectSoFar = true;

                    // Check if each input matches the gathered plant's number
                    for (size_t i = 0; i < playerInput.size(); ++i) {
                        if (playerInput[i] != gatheredPlants[i]->number) {
                            isCorrectSoFar = false;
                            break;
                        }
                    }

                    if (!isCorrectSoFar) {
                        // If the input is incorrect, reset the player input and trigger a Game Over state
                        playerInput.clear();
                        gameState = GameState::GameOver;
                    }
                    else {
                        // If the player has completed the sequence correctly, proceed to the next cutscene
                        playerInput.clear(); // Reset input for the next cutscene
                        proceedToNextCutscene();
                    }
                }
            }

            // Handle skip cutscene (Space key)
            else if (sfmlEvent.key.code == sf::Keyboard::Space) {
                playerInput.clear(); // Clear input if skipped
                proceedToNextCutscene(); // Proceed to next cutscene
            }
            // Handle exit (Escape key)
            else if (sfmlEvent.key.code == sf::Keyboard::Escape) {
                gameState = GameState::Exiting;
            }
            break;

        default:
            break;
        }
    }
}


void Game::pollEventsGameOver()
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



void Game::checkPlayer()
{
    if (world.isPlayerDead())
    {
        gameState = GameState::GameOver;
    }
}

void Game::proceedToNextCutscene() {
    switch (currentCutscene) {
    case AllCutscenes::Ghost1:
        currentCutscene = AllCutscenes::Ghost2;
        break;
    case AllCutscenes::Ghost2:
        currentCutscene = AllCutscenes::Ghost3;
        break;
    case AllCutscenes::Ghost3:
        currentCutscene = AllCutscenes::Sister;
        break;
    default:
        break;
    }

    gameState = GameState::Leveling;

    world.isCutScene = false;        // End cutscene state
    world.removeGhost();             // Remove current ghost
    world.setStartPositionPlayer();  // Reset player position

    configuration.proceed();         // Proceed to the next level or configuration
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
    switch (configuration.currentLevel)
    {
    case Configuration::Level::Level1:
        //configuration.loadPlayer(window);
        configuration.loadLevel1(window);
        break;
    case Configuration::Level::Level2:
        configuration.loadLevel2(window);
        break;
    case Configuration::Level::Level3:
        configuration.loadLevel3(window);
        break;
    case Configuration::Level::Level4:
        configuration.loadLevel4(window);
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
    window.draw(bg);
    playCurrentScene();
    pollEventsCutscene();
    window.display();
}

void Game::handleGameOverScreen()
{
    window.clear(sf::Color::Black);
    pollEventsGameOver();
    window.draw(gameOver);
    window.display();
}

void Game::playCurrentScene()
{
    switch (currentCutscene)
    {
    case AllCutscenes::Ghost1:
        window.draw(ghost1Full);
        break;
    case AllCutscenes::Ghost2:
        window.draw(ghost2Full);
        break;
    case AllCutscenes::Ghost3:
        window.draw(ghost3Full);
        break;
    case AllCutscenes::Sister:
        window.draw(sisterFull);
    }

    window.draw(flowerTable);

}

void Game::update(float deltaTime)
{
    world.update(deltaTime);

    checkPlayer();

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
        case GameState::GameOver:
            handleGameOverScreen();
            break;
        case GameState::Exiting:
            window.close();
            break;
        }
    }
}
