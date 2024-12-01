#ifndef GHOST_H
#define GHOST_H

#include "entity.h"
#include "world.h"

class Ghost : public Entity
{
private:

	sf::RenderWindow& window;
	sf::Clock sinceLastChangeOfDirection;

	int randomTimeToChangeDirection;
	int lastDirection;

	sf::Vector2f velocity;        // Current velocity of the ghost

	sf::Vector2f direction;

	const sf::Vector2f startingPoint;

	float speed = 400.f;

	bool directionNeedToBeChanged;

	float changeDirectionTime;   // Time until direction change
	
	float elapsedTime;

public:
	Ghost(World& world, sf::RenderWindow& window);

	bool isToGoBack;
	bool isOnTheRightPlace;

	virtual void update(float deltaTime);
	virtual void onCollide(Entity& other) override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	void script(float deltaTime);

};
#endif POTION_H