#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include "resourseManager.h"
#include "random.h"


class World;

class Entity : public sf::Drawable
{
public:
	enum class Type
	{
		Player,
		Potion,
		Plant,
		Ghost
	};
	
	Entity(World& world, ResourceManager::Texture textureID, Type type);
	virtual ~Entity();

	template <typename... Args>
	void setPosition(Args&&... args)
	{
		sprite.setPosition(std::forward<Args>(args)...);
	}

	void move(const sf::Vector2f& offset) {
		sprite.move(offset);
	}

	void changeTexture(ResourceManager::Texture textureID);

	const sf::Vector2f& getPosition() const;

	const sf::Vector2u getSpriteSize() const;

	Type getType() const;


	const sf::Sprite& getSprite() const;


	virtual void update(float deltaTime) = 0;
	virtual void onCollide(Entity& other) = 0;


	bool toRemove = false;

	int number;


protected:
	friend class Player;
	friend class Plant;
	friend class Potion;
	friend class Ghost;

	sf::Sprite sprite;


	World& world;

	Type type;

	sf::Vector2u spriteSize;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};
#endif
