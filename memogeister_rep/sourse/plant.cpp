#include "../include/plant.h"

Plant::Plant(World& world, sf::RenderWindow& window) : Entity(world, ResourceManager::Texture::Plant1, Type::Plant), window(window)
{
	setPosition(Random::GenerateInt(100, sf::VideoMode::getDesktopMode().width - 100), Random::GenerateInt(100, sf::VideoMode::getDesktopMode().height)-100);

	unsigned int randomInt = Random::GenerateInt(0,6);
	if (randomInt == 0)
	{
		changeTexture(ResourceManager::Texture::Plant1);
	}
	else if (randomInt == 1)
	{
		changeTexture(ResourceManager::Texture::Plant2);
	}
	else if (randomInt == 2)
	{
		changeTexture(ResourceManager::Texture::Plant3);
		sprite.setScale({ 0.5,0.5 });
	}
	else if (randomInt == 3)
	{
		changeTexture(ResourceManager::Texture::Plant4);
		sprite.setScale({ 0.75,0.75 });
	}
	else if (randomInt == 4)
	{
		changeTexture(ResourceManager::Texture::Plant5);
		sprite.setScale({ 1.15,1.15 });
	}
	else if (randomInt == 5)
	{
		changeTexture(ResourceManager::Texture::Plant6);
		sprite.setScale({ 0.25,0.25 });
	}
	else if (randomInt == 6)
	{
		changeTexture(ResourceManager::Texture::Plant7);
		sprite.setScale({ 0.25,0.25 });
	}

	world.add(std::make_unique<Plant>(*this));
}

void Plant::update(float deltaTime)
{
}

void Plant::onCollide(Entity& other)
{
	switch (other.getType())
	{
	case Type::Player:
		toRemove = true;
		break;
	default:
		break;
	}
}

void Plant::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Entity::draw(target, states);
}
