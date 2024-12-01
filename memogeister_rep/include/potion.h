#ifndef POTION_H
#define POTION_H

#include "entity.h"
#include "world.h"

class Potion : public Entity
{
private:

	sf::RenderWindow& window;

public:
	Potion(World& world, sf::RenderWindow& window);


	virtual void update(float deltaTime);
	virtual void onCollide(Entity& other) override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};
#endif POTION_H