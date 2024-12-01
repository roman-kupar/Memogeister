#include "../include/entity.h"

Entity::Entity(World& world, ResourceManager::Texture textureID, Type type) : world(world), type(type)
{
    const sf::Texture& texture = ResourceManager::textures.at(textureID);
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2.0f, texture.getSize().y / 2.0f);


}

Entity::~Entity() {}

void Entity::changeTexture(ResourceManager::Texture textureID)
{
    const sf::Texture& texture = ResourceManager::textures.at(textureID);

    sprite.setTexture(texture, true);
    sprite.setOrigin(texture.getSize().x / 2.0f, texture.getSize().y / 2.0f);
    spriteSize = texture.getSize();
}

const sf::Vector2f& Entity::getPosition() const
{
    return sprite.getPosition();
}

const sf::Vector2u Entity::getSpriteSize() const
{
    return spriteSize;
}

Entity::Type Entity::getType() const
{
    return type;
}

const sf::Sprite& Entity::getSprite() const
{
    return sprite;
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite);

}