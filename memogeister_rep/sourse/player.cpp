#include "../include/player.h"

Player::Player(World& world, sf::RenderWindow& window) : Entity(world, ResourceManager::Texture::PlayerTexture, Type::Player), window(window), currentAngle(90), isRotationSet(false)
{
	setPosition(300.f, 300.f);

	world.add(std::make_unique<Player>(*this));
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Entity::draw(target, states);
}

void Player::updateInput(float deltaTime)
{
    sf::Vector2f movementVector(0.f, 0.f);

    static bool keyPreviouslyPressed = false;

    // Down or S key
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && !keyPreviouslyPressed)
    {
        movementVector.y += speed;
        sprite.setRotation(180.f); // Facing down
        keyPreviouslyPressed = true;
    }
    // Up or W key
    else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && !keyPreviouslyPressed)
    {
        movementVector.y -= speed;
        sprite.setRotation(0.f); // Facing up
        keyPreviouslyPressed = true;
    }
    // Left or A key
    else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && !keyPreviouslyPressed)
    {
        movementVector.x -= speed;
        sprite.setRotation(-90.f); // Facing left
        keyPreviouslyPressed = true;
    }
    // Right or D key
    else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && !keyPreviouslyPressed)
    {
        movementVector.x += speed;
        sprite.setRotation(90.f); // Facing right
        keyPreviouslyPressed = true;
    }
    else
    {
        // No keys pressed: reset the flag
        keyPreviouslyPressed = false;
    }

    // Move the sprite
    sprite.move(movementVector * deltaTime);
}


void Player::update(float deltaTime)
{
	updateInput(deltaTime);

}

void Player::onCollide(Entity& other)
{}