#include "map.hpp"
#include "constants.hpp"
#include "engine.hpp"
#include "tools.hpp"

/**
 * Constructeur
 */
Map::Map()
{
}

/**
 * Destructeur
 */
Map::~Map()
{
	levels_.clear();
}

/**
 * Initialisation de la carte
 * 
 * Génération d'un nombre aléatoire pour la génération de la carte basé sur un seed
 * création de la carte (tile)
 * création de la carte (fov)
 * création d'un bsp tree pour la génération aléatoire
 * 
 * Accès à une case x,y -> map[x + y * width]
 */
void Map::initialize()
{
	currentLevel_ = 0;
	
	//DEV création d'un level
	createLevel(0, MAP_WIDTH, MAP_HEIGHT);
}

/**
 * Création d'un level
 */
void Map::createLevel(const int& plevel, const int& pwidth, const int& pheight)
{
	Level* lvl = new Level(pwidth, pheight);
	lvl->generate();
	lvl->generateBsp();
	levels_[plevel] = lvl;
}
 
/**
 * Dessin du level courant
 */
void Map::render()
{
	levels_[currentLevel_]->render();
}

/**
 * Mise à jour du level courant
 */
void Map::update()
{
	levels_[currentLevel_]->update();
}

/**
 * Retourne le level courant
 */
Level& Map::getCurrentLevel()
{
	return *levels_[currentLevel_];
}

/**
 * Révèle le level courant
 */
void Map::revealCurrentLevel()
{
	levels_[currentLevel_]->reveal();
}