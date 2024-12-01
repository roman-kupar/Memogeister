#ifndef PLAYER_H
#define PLAYER_H

#include"world.h"
#include"entity.h"

class Player : public Entity
{
private:

	sf::RenderWindow& window;

	float currentAngle;
	bool isRotationSet;

	sf::Vector2f lastDirection;

	float speed = 800.f;

public:
	Player(World& world, sf::RenderWindow& window);

	void updateInput(float deltaTime);

	virtual void update(float deltaTime);
	virtual void onCollide(Entity& other) override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

#endif	
