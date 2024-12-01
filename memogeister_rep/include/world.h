#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include "SFML/Window.hpp"
#include <list>
#include "collision.h"
#include "entity.h"
#include "ghost.h"
#include "player.h"

class World : public sf::Drawable
{
public:
	World();
	~World();


	void update(float deltaTime);
	//void updateScore(unsigned int points);

	//void add(std::unique_ptr<Entity> entity);

	//void checkCollision();

	//void playerReady();

	int getWidth() const;
	int getHeight() const;

	bool isCutScene = false;

	void checkCollision();

	sf::Vector2f getPlayerPosition() const;
	//sf::Vector2f getMousePosition() const;

	//Entity* getPlayer();
	//void setPlayer(Entity* player);
	bool isPlayerDead() const;

	//std::list<std::unique_ptr<Entity>>& getEntities();

	//void clearEntities();

	//void clearAllEntites();

	void add(std::unique_ptr<Entity> entity);

	bool checkIfAllFlowersGathered();

	void sendGhostBack();

	void startCutScene();

private:

	unsigned int width;
	unsigned int height;
	
	std::list<std::unique_ptr<Entity>> entities;
	Ghost* ghost = nullptr;
	Player* player = nullptr;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif WORLD_H	
