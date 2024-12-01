#include "../include/ghost.h"
#include <iostream>

Ghost::Ghost(World& world, sf::RenderWindow& window) : Entity(world, ResourceManager::Texture::Ghost1, Type::Ghost), window(window), elapsedTime(0.0f), startingPoint(sf::VideoMode::getDesktopMode().width - 65.f, sf::VideoMode::getDesktopMode().height / 2)
{
	directionNeedToBeChanged = false;
	isOnTheRightPlace = false;

	setPosition(startingPoint);

	sprite.setRotation(-90);

	randomTimeToChangeDirection = Random::GenerateInt(1, 3);

	direction = sf::Vector2f(-speed,0);
	lastDirection = 0;
	isToGoBack = false;

	world.add(std::make_unique<Ghost>(*this));

	sinceLastChangeOfDirection.restart();
}

void Ghost::update(float deltaTime)
{
	if (isToGoBack)
	{
		sf::Vector2f distanceVec = startingPoint - getPosition();
		float distance = std::sqrt(distanceVec.x * distanceVec.x + distanceVec.y * distanceVec.y);

		const float threshold = 5.0f; // Adjust as needed

		if (distance <= threshold) {
			setPosition(startingPoint); // Teleport to the starting point
			sprite.setRotation(-90);
			isOnTheRightPlace = true;
		}
		else {
			script(deltaTime);
		}

	}
	else
	{
		if ((getPosition().x < 50.f || getPosition().x > window.getSize().x - 50.f) || getPosition().y < 50.f || getPosition().y > window.getSize().y - 50.f)
		{
			directionNeedToBeChanged = true;
		}

		if (sinceLastChangeOfDirection.getElapsedTime().asSeconds() >= randomTimeToChangeDirection || directionNeedToBeChanged)
		{
			int randomDirection = Random::GenerateInt(0, 3);

			if (lastDirection == randomDirection)
			{
				return update(deltaTime);
			}
			else
			{
				lastDirection = randomDirection;
			}

			switch (randomDirection)
			{
			case 0:
				direction = sf::Vector2f(-speed, 0);
				sprite.setRotation(-90);
				randomTimeToChangeDirection = Random::GenerateInt(1, 2);
				sinceLastChangeOfDirection.restart();
				break;
			case 1:
				direction = sf::Vector2f(speed, 0);
				sprite.setRotation(90);
				randomTimeToChangeDirection = Random::GenerateInt(1, 2);
				sinceLastChangeOfDirection.restart();

				break;
			case 2:
				direction = sf::Vector2f(0, speed);
				sprite.setRotation(180);
				randomTimeToChangeDirection = Random::GenerateInt(1, 2);
				sinceLastChangeOfDirection.restart();
				break;
			case 3:
				direction = sf::Vector2f(0, -speed);
				sprite.setRotation(0);
				randomTimeToChangeDirection = Random::GenerateInt(1, 2);
				sinceLastChangeOfDirection.restart();
				break;

			}

			directionNeedToBeChanged = false;
		}

		move(direction * deltaTime);
	}
	

}

void Ghost::onCollide(Entity& other)
{
}

void Ghost::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Entity::draw(target, states);
}

void Ghost::script(float deltaTime)
{
	// Calculate the direction vector
	direction = startingPoint - getPosition();

	// Calculate the length (magnitude) of the direction vector
	float magnitude = std::sqrt(direction.x * direction.x + direction.y * direction.y);

	// Normalize the vector if its magnitude is not zero
	if (magnitude != 0.0f) {
		direction /= magnitude; // Normalize the vector
	}

	// Rotate to face the direction of movement
	float angle = std::atan2(direction.y, direction.x) * 180.0f / 3.14159f; // Convert radians to degrees
	sprite.setRotation(angle + 90.0f); // Add 90 degrees since the sprite points upwards

	// Move the ghost in the normalized direction
	float speed = 400.0f; // Set your desired speed
	move(direction * speed * deltaTime);
}