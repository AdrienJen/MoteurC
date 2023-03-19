#ifndef CMD_ENGINE_TAGMANAGER_H
#define CMD_ENGINE_TAGMANAGER_H

#include <string>
#include <map>

class TagManager {
private:
    static TagManager* instance;

	// Constructeur privé pour empêcher la création d'objets depuis l'extérieur
    TagManager() { m_TagManager = {}; }// Initialise la liste des tags à vide

public:
    std::map<std::string, int> m_TagManager;

	// Retourne l'instance unique de la classe TagManager (singleton)
    static TagManager* getInstance();

	// Crée un nouveau tag avec le nom spécifié, retourne son identifiant unique
    int createTag(std::string);
};


#endif