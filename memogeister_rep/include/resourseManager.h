#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include<unordered_map>
#include<SFML/Graphics/Texture.hpp>

class ResourceManager
{
private: 
	
public:

	enum class Texture
	{
		PlayerTexture,
		Potion1,
		Potion2,
		Potion3,
		BackgroundImage,
		MainMenu,
		Heartshapes,
		bg,
		gameOverScreen,
		tableOfFlowers,
		introductionPaper,
		Ghost1Full,
		Ghost2Full,
		Ghost3Full,
		SisterFull,
		Ghost1,
		Ghost2,
		Ghost3,
		Sister,
		Plant1,
		Plant2,
		Plant3,
		Plant4,
		Plant5,
		Plant6,
		Plant7
	};


	static std::unordered_map<Texture, sf::Texture> textures;

	static void initializeTextures();

};
#endif RESOURCEMANAGER_H