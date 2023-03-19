#include "TagManager.h"
#include "Hashing.h"

// Initialisation de l'instance de TagManager
TagManager* TagManager::instance = 0;

// R�cup�ration de l'instance unique de TagManager
TagManager* TagManager::getInstance() {
	// Si l'instance n'a pas encore �t� cr��e, on la cr�e maintenant
	if (!instance)
		instance = new TagManager;
	return instance;
}

// Cr�ation d'un tag et stockage de sa valeur hash�e dans le TagManager
int TagManager::createTag(std::string tag) {
	// Utilisation de la fonction de hachage MurmurHash3 pour obtenir un entier unique bas� sur le tag
	int hashed = Hashing::murmur3_32(tag.c_str(), tag.size(), 9843713);
	// Stockage du tag et de sa valeur hash�e dans la map m_TagManager
	m_TagManager.insert(std::pair<std::string, int>(tag, hashed));
	// Retourne la valeur hash�e du tag, qui peut �tre utilis�e comme identifiant unique pour le tag
	return hashed;
}