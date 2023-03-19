#ifndef CMD_ENGINE_TAGMANAGER_H
#define CMD_ENGINE_TAGMANAGER_H

#include <string>
#include <map>

class TagManager {
private:
    static TagManager* instance;

	// Constructeur priv� pour emp�cher la cr�ation d'objets depuis l'ext�rieur
    TagManager() { m_TagManager = {}; }// Initialise la liste des tags � vide

public:
    std::map<std::string, int> m_TagManager;

	// Retourne l'instance unique de la classe TagManager (singleton)
    static TagManager* getInstance();

	// Cr�e un nouveau tag avec le nom sp�cifi�, retourne son identifiant unique
    int createTag(std::string);
};


#endif