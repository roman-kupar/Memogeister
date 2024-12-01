#include"../include/collision.h"

bool Collision::CheckCircleCollision(const sf::Sprite& first, const sf::Sprite& second)
{
	sf::Vector2f rectangle1(static_cast<float>(first.getTextureRect().width), static_cast<float>(first.getTextureRect().height));
	rectangle1.x *= first.getScale().x;
	rectangle1.y *= first.getScale().y;

	sf::Vector2f rectangle2(static_cast<float>(second.getTextureRect().width), static_cast<float>(second.getTextureRect().height));
	rectangle2.x *= second.getScale().x;
	rectangle2.y *= second.getScale().y;

	float radius1 = (rectangle1.x + rectangle1.y) / 4;
	float radius2 = (rectangle2.x + rectangle2.y) / 4;

	float horDistance = first.getPosition().x - second.getPosition().x;
	float vertDistance = first.getPosition().y - second.getPosition().y;

	return (horDistance * horDistance) + (vertDistance * vertDistance) <= (radius1 + radius2) * (radius1 + radius2);
}


bool Collision::checkSimpleCollision(const sf::Sprite& first, const sf::Sprite& second)
{
	// Get the bounding boxes of the two sprites
	sf::Vector2f rectangle1(static_cast<float>(first.getTextureRect().width), static_cast<float>(first.getTextureRect().height));
	rectangle1.x *= first.getScale().x;
	rectangle1.y *= first.getScale().y;

	sf::Vector2f rectangle2(static_cast<float>(second.getTextureRect().width), static_cast<float>(second.getTextureRect().height));
	rectangle2.x *= second.getScale().x;
	rectangle2.y *= second.getScale().y;

	// Get the positions of the two sprites
	sf::Vector2f position1 = first.getPosition();
	sf::Vector2f position2 = second.getPosition();

	// Check for overlap in the X and Y axes
	bool collisionX = position1.x < position2.x + rectangle2.x && position1.x + rectangle1.x > position2.x;
	bool collisionY = position1.y < position2.y + rectangle2.y && position1.y + rectangle1.y > position2.y;

	// Return true if there is a collision
	return collisionX && collisionY;
}

bool Collision::checkCenterCollision(const sf::Sprite& first, const sf::Sprite& second, float collisionRadius) {
	// Get the centers of the two sprites
	sf::Vector2f center1 = first.getPosition() + sf::Vector2f(first.getTextureRect().width * first.getScale().x / 2.0f,
		first.getTextureRect().height * first.getScale().y / 2.0f);
	sf::Vector2f center2 = second.getPosition() + sf::Vector2f(second.getTextureRect().width * second.getScale().x / 2.0f,
		second.getTextureRect().height * second.getScale().y / 2.0f);

	// Calculate the distance between the two centers
	float dx = center1.x - center2.x;
	float dy = center1.y - center2.y;
	float distance = std::sqrt(dx * dx + dy * dy);

	// Check if the distance is less than or equal to the collision radius
	return distance <= collisionRadius;
}

void Collision::resolveCollision(Entity& first, Entity& second) {
	//sf::FloatRect rect1 = first.getSprite().getGlobalBounds();
	//sf::FloatRect rect2 = second.getSprite().getGlobalBounds();

	//bool dontMove1 = false, dontMove2 = false;

	//if (first.getType() == Entity::Type::BigAsteroid || first.getType() == Entity::Type::SmallAsteroid || first.getType() == Entity::Type::Boss) 
	//	dontMove1 = true;
	//if (second.getType() == Entity::Type::BigAsteroid || second.getType() == Entity::Type::SmallAsteroid || second.getType() == Entity::Type::Boss)
	//	dontMove2 = true;
	//if (first.getType() == Entity::Type::PlayerBullet || first.getType() == Entity::Type::EnemyBullet || 
	//	second.getType() == Entity::Type::PlayerBullet || second.getType() == Entity::Type::EnemyBullet)
	//{
	//	return;
	//}

	//float overlapX = std::min(rect1.left + rect1.width, rect2.left + rect2.width) - std::max(rect1.left, rect2.left);
	//float overlapY = std::min(rect1.top + rect1.height, rect2.top + rect2.height) - std::max(rect1.top, rect2.top);

	//if (overlapX > 0 && overlapY > 0) {
	//	if (overlapX < overlapY) {
	//		float sign = (rect1.left + rect1.width / 2 < rect2.left + rect2.width / 2) ? -1.0f : 1.0f;
	//		float moveX = overlapX * sign / 2.0f;

	//		if (!dontMove1)
	//			first.move(sf::Vector2f(moveX, 0));
	//		if (!dontMove2)
	//			second.move(sf::Vector2f(-moveX, 0));
	//	}
	//	else {
	//		float sign = (rect1.top + rect1.height / 2 < rect2.top + rect2.height / 2) ? -1.0f : 1.0f;
	//		float moveY = overlapY * sign / 2.0f;
	//		if (!dontMove1)
	//			first.move(sf::Vector2f(0, moveY));
	//		if (!dontMove2)
	//			second.move(sf::Vector2f(0, -moveY));
	//	}
	//}
}