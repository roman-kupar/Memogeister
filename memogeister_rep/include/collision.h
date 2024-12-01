#ifndef COLLISION_H
#define COLLISION_H

#include <SFML/Graphics.hpp>
#include"entity.h"

class Collision
{
public:
	Collision() = delete;

	static bool CheckCircleCollision(const sf::Sprite& first, const sf::Sprite& second);
	static bool checkSimpleCollision(const sf::Sprite& first, const sf::Sprite& second);
	static bool checkCenterCollision(const sf::Sprite& first, const sf::Sprite& second, float collisionRadius);

	static void resolveCollision(Entity& first, Entity& second);
};

#endif

