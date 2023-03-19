#include "TagManager.h"
#include "Hashing.h"

// Initialisation de l'instance de TagManager
TagManager* TagManager::instance = 0;

// Récupération de l'instance unique de TagManager
TagManager* TagManager::getInstance() {
	// Si l'instance n'a pas encore été créée, on la crée maintenant
	if (!instance)
		instance = new TagManager;
	return instance;
}

// Création d'un tag et stockage de sa valeur hashée dans le TagManager
int TagManager::createTag(std::string tag) {
	// Utilisation de la fonction de hachage MurmurHash3 pour obtenir un entier unique basé sur le tag
	int hashed = Hashing::murmur3_32(tag.c_str(), tag.size(), 9843713);
	// Stockage du tag et de sa valeur hashée dans la map m_TagManager
	m_TagManager.insert(std::pair<std::string, int>(tag, hashed));
	// Retourne la valeur hashée du tag, qui peut être utilisée comme identifiant unique pour le tag
	return hashed;
}