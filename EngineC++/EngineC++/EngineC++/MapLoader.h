#pragma once
#include <string>
#include <vector>
#include "Scene.h"
#include "Factory.h"
class MapLoader {
public:
	MapLoader();
	void LoadMap(Factory* fac, Scene* scene, std::string& fileName);
private:
	void RemoveWordFromLine(std::string& line, const std::string& word);
	std::vector<std::string> Split(const std::string& s, const std::string& delimiter);

	//caractères composants la surface de jeu
	std::string firstSizeChar = "[";
	std::string lastSizeChar = "]";
	std::string sizeDelimiter = ",";
	std::string labelDelimiter = " ";
};
