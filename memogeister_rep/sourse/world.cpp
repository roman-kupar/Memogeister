#include "../include/world.h"
#include <iostream>

void World::add(std::unique_ptr<Entity> entity)
{
	if (Ghost* newGhost = dynamic_cast<Ghost*>(entity.get())) {
		ghost = newGhost; 
	}
	else if (Player* newPlayer = dynamic_cast<Player*>(entity.get())) {
		player = newPlayer;
	}

	entities.push_back(std::move(entity));

}

bool World::checkIfAllFlowersGathered()
{
	for (const auto& entityPtr : entities) {
		if (entityPtr->getType() == Entity::Type::Plant)
			return false;
	}

	return true;
}

void World::sendGhostBack()
{
	ghost->isToGoBack = true;
}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto entity = entities.rbegin(); entity != entities.rend(); ++entity)
		target.draw(*(*entity), states);
}

World::World()
{
	width = sf::VideoMode::getDesktopMode().width;
	height = sf::VideoMode::getDesktopMode().height;

}

World::~World()
{
}

void World::update(float deltaTime)
{
	checkCollision();

	auto& entitiesRef = entities;
	entities.erase(std::remove_if(entities.begin(), entities.end(), [this, &deltaTime, &entitiesRef](const auto& entityPtr) {
		Entity& entity = *entityPtr;

		entity.update(deltaTime);

		return entityPtr->toRemove;
		}), entities.end());

	if (checkIfAllFlowersGathered() && !ghost->isOnTheRightPlace)
		sendGhostBack();

	else if (ghost->isOnTheRightPlace)
	{
		sf::Vector2f playerPos = player->getPosition();
		sf::Vector2f ghostPos = ghost->getPosition();

		float interactionRadius = 30.f;

		bool isPlayerInsideSquare =
			playerPos.x >= ghostPos.x - interactionRadius &&
			playerPos.x <= ghostPos.x + interactionRadius &&
			playerPos.y >= ghostPos.y - interactionRadius &&
			playerPos.y <= ghostPos.y + interactionRadius;

		if (isPlayerInsideSquare && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			std::cout << "Player inside interaction square. Starting cutscene...\n";
			startCutScene();
		}
		else {
			if (!isPlayerInsideSquare) {
				std::cout << "Player outside interaction square.\n";
			}
			if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				std::cout << "Space key not pressed.\n";
			}
		}
	}
}

void World::startCutScene()
{
	std::cout << "works cool";
	isCutScene = true;
}

void World::checkCollision()
{
	for (auto it1 = entities.begin(); it1 != entities.end(); ++it1)
	{
		for (auto it2 = std::next(it1); it2 != entities.end(); ++it2)
		{
			Entity& entity1 = *(*it1);
			Entity& entity2 = *(*it2);


			if (Collision::checkCenterCollision(entity1.getSprite(), entity2.getSprite(), 30.f))
			{
				entity1.onCollide(entity2);
				entity2.onCollide(entity1);
			}
		}
	}
}
