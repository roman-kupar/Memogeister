#include "../include/plant.h"

Plant::Plant(World& world, sf::RenderWindow& window) : Entity(world, ResourceManager::Texture::Plant1, Type::Plant), window(window)
{
	setPosition(Random::GenerateInt(100, sf::VideoMode::getDesktopMode().width - 100), Random::GenerateInt(100, sf::VideoMode::getDesktopMode().height)-100);

	unsigned int randomInt = Random::GenerateInt(0,9);
	if (randomInt == 0)
	{
		changeTexture(ResourceManager::Texture::Plant1);
		number = 6;
	}
	else if (randomInt == 1)
	{
		changeTexture(ResourceManager::Texture::Plant2);
		number = 7;
	}
	else if (randomInt == 2)
	{
		changeTexture(ResourceManager::Texture::Plant3);
		sprite.setScale({ 0.5,0.5 });
		number = 5;
	}
	else if (randomInt == 3)
	{
		changeTexture(ResourceManager::Texture::Plant4);
		number = 3;
		sprite.setScale({ 0.75,0.75 });
	}
	else if (randomInt == 4)
	{
		changeTexture(ResourceManager::Texture::Plant5);
		number = 4;
		sprite.setScale({ 1.15,1.15 });
	}
	else if (randomInt == 5)
	{
		changeTexture(ResourceManager::Texture::Plant6);
		number = 2;
		sprite.setScale({ 0.25,0.25 });
	}
	else if (randomInt == 6)
	{
		changeTexture(ResourceManager::Texture::Plant7);
		number = 1;
		sprite.setScale({ 0.25,0.25 });
	}
	else if (randomInt == 7)
	{
		changeTexture(ResourceManager::Texture::Potion1);
		number = 9;
	}
	else if (randomInt == 8)
	{
		changeTexture(ResourceManager::Texture::Potion2);
		number = 8;
	}
	else if (randomInt == 9)
	{
		number = 7;
		changeTexture(ResourceManager::Texture::Potion3);
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
