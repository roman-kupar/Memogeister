#ifndef PLANT_H
#define PLANT_H

#include "entity.h"
#include "world.h"

class Plant : public Entity
{
private:

	sf::RenderWindow& window;


public:
	Plant(World& world, sf::RenderWindow& window);


	virtual void update(float deltaTime);
	virtual void onCollide(Entity& other) override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};
#endif POTION_H