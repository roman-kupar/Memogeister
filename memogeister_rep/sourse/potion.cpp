#include "../include/potion.h"

Potion::Potion(World& world, sf::RenderWindow& window) : Entity(world, ResourceManager::Texture::Potion1, Type::Potion), window(window)
{
	int randomChoice = Random::GenerateInt(1,2);

	if (randomChoice == 1)
	{}
	else if (randomChoice == 2)
	{}

	setPosition(300.f, 300.f);

	world.add(std::make_unique<Potion>(*this));
}


void Potion::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Entity::draw(target, states);
}

void Potion::update(float deltaTime)
{
}

void Potion::onCollide(Entity& entity)
{

}