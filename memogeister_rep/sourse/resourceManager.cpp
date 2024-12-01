#include"../include/resourseManager.h"
#include <iostream>

std::unordered_map<ResourceManager::Texture, sf::Texture> ResourceManager::textures;

void ResourceManager::initializeTextures()
{
	sf::Texture playerTexture, potion1, potion2, potion3, backgroundImage,mainMenu, heartShape, ghost1Full, ghost1,plant1, plant2, plant3, plant4, plant5, plant6, plant7;

	if (!playerTexture.loadFromFile("memogeister_rep/resources/playercharacter.png") ||
		!potion1.loadFromFile("memogeister_rep/resources/trank1.png") ||
		!potion2.loadFromFile("memogeister_rep/resources/trank2.png") ||
		!potion3.loadFromFile("memogeister_rep/resources/trank3.png") ||
		!backgroundImage.loadFromFile("memogeister_rep/resources/Background.png") ||
		!mainMenu.loadFromFile("memogeister_rep/resources/Mainmenu.png") ||
		!heartShape.loadFromFile("memogeister_rep/resources/IMG_0188.png") ||
		!ghost1Full.loadFromFile("memogeister_rep/resources/ghostfull1.png") ||
		!ghost1.loadFromFile("memogeister_rep/resources/ghost1.png") ||
		!plant1.loadFromFile("memogeister_rep/resources/blumeevelina1.png") ||
		!plant2.loadFromFile("memogeister_rep/resources/maiglevelina.png") ||
		!plant3.loadFromFile("memogeister_rep/resources/SchneegloeckchenGemalt.png") ||
		!plant4.loadFromFile("memogeister_rep/resources/mohn.png") ||
		!plant5.loadFromFile("memogeister_rep/resources/IMG_0186.png") ||
		!plant6.loadFromFile("memogeister_rep/resources/shroom1.png") ||
		!plant7.loadFromFile("memogeister_rep/resources/shroom2.png"))
	{std::cout << "Unable to load images"; }


	textures.insert(std::make_pair(Texture::PlayerTexture, playerTexture));
	textures.insert(std::make_pair(Texture::Potion1, potion1));
	textures.insert(std::make_pair(Texture::Potion2, potion2));
	textures.insert(std::make_pair(Texture::Potion3, potion3));
	textures.insert(std::make_pair(Texture::BackgroundImage, backgroundImage));
	textures.insert(std::make_pair(Texture::MainMenu, mainMenu));
	textures.insert(std::make_pair(Texture::Heartshapes, heartShape));
	textures.insert(std::make_pair(Texture::Ghost1Full, ghost1Full));
	textures.insert(std::make_pair(Texture::Ghost1, ghost1));
	textures.insert(std::make_pair(Texture::Plant1, plant1));
	textures.insert(std::make_pair(Texture::Plant2, plant2));
	textures.insert(std::make_pair(Texture::Plant3, plant3));
	textures.insert(std::make_pair(Texture::Plant4, plant4));
	textures.insert(std::make_pair(Texture::Plant5, plant5));
	textures.insert(std::make_pair(Texture::Plant6, plant6));
	textures.insert(std::make_pair(Texture::Plant7, plant7));

}