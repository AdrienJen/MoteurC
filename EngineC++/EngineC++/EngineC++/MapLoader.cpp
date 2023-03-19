#include "MapLoader.h" // Inclusion de l'en-t�te de la classe MapLoader
#include <fstream> // Inclusion de la biblioth�que pour lire et �crire dans des fichiers
#include <iostream> // Inclusion de la biblioth�que pour entr�es/sorties
#include <map> // Inclusion de la biblioth�que pour utiliser un dictionnaire
#include "GameObject.h" // Inclusion de l'en-t�te de la classe GameObject
#include "Transform.h" // Inclusion de l'en-t�te de la classe Transform
#include "ASCIIRenderer.h" // Inclusion de l'en-t�te de la classe ASCIIRenderer
#include "TagManager.h" // Inclusion de l'en-t�te de la classe TagManager

// Enum�ration des diff�rents types de donn�es que peut contenir le fichier de carte
enum MapDataType : int { None, Size, Labels, Map };

// Constructeur de la classe MapLoader
MapLoader::MapLoader() {
}

// Fonction pour charger une carte � partir d'un fichier
void MapLoader::LoadMap(Factory* fac, Scene* scene, std::string& fileName) {
	std::ifstream infile("map1.txt"); // Ouverture du fichier en lecture

	std::map<char, int> content; // Dictionnaire pour stocker la correspondance entre un caract�re et le type de cellule correspondant

	MapDataType currentData = None; // Type de donn�es actuellement lu dans le fichier
	int currentLine = 0; // Num�ro de la ligne actuellement lue dans le fichier

	for (std::string line; std::getline(infile, line, '\n'); ) { // Parcours du fichier ligne par ligne

		if (line[0] == '>') { // Si la ligne commence par '>', on change le type de donn�es
			if (line == ">size") {
				currentData = Size;
			}
			else if (line == ">labels") {
				currentData = Labels;
			}
			else if (line == ">map") {
				currentData = Map;
			}
		}
		else { // Si la ligne ne commence pas par '>', on lit les donn�es
			std::vector<std::string> substrings; // Vecteur pour stocker les sous-cha�nes s�par�es par un d�limiteur
			int currentChar = 0; // Num�ro du caract�re actuellement lu dans la ligne

			switch (currentData) {
			case Map: // Si on lit la carte
				currentChar = 0; // On r�initialise le num�ro de caract�re � 0 pour la nouvelle ligne
				for (char& cell : line) { // Parcours de chaque caract�re de la ligne

					auto cellType = content.find(cell); // Recherche du type de cellule correspondant au caract�re dans le dictionnaire
					if (cellType != content.end()) { // Si le type de cellule existe dans le dictionnaire
						Position pos = Position(currentChar, currentLine); // Cr�ation de la position de la cellule dans la carte
						GameObject* go = fac->createObject(cellType->second, pos, cell); // Cr�ation d'un GameObject avec le type de cellule et la position
						scene->Instantiate(go); // Ajout du GameObject � la sc�ne
					}
					currentChar++; // Passage au caract�re suivant dans la ligne
				}
				currentLine++; // Passage � la ligne suivante
				break;
			case Labels:
				substrings = Split(line, labelDelimiter);
				if (substrings.size() == 2) {
					content[substrings[1].c_str()[0]] = TagManager::getInstance()->m_TagManager[substrings[0]];
				}
				break;
			case Size:
				RemoveWordFromLine(line, firstSizeChar);
				RemoveWordFromLine(line, lastSizeChar);
				substrings = Split(line, sizeDelimiter);
				int width = atoi(substrings[0].c_str());
				int height = atoi(substrings[1].c_str());
				scene->SetSceneDimensions(width, height);
				break;
			}
		}
	}
}
void MapLoader::RemoveWordFromLine(std::string& line, const std::string& word)
{
	auto n = line.find(word);
	if (n != std::string::npos)
	{
		line.erase(n, word.length());
	}
}
// for string delimiter
std::vector<std::string> MapLoader::Split(const std::string& s, const std::string& delimiter) {
	size_t pos_start = 0, pos_end, delim_len = delimiter.length();
	std::string token;
	std::vector<std::string> res;

	while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
		token = s.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		res.push_back(token);
	}

	res.push_back(s.substr(pos_start));
	return res;
}
