#pragma once
#ifndef CMD_ENGINE_FACTORY_H
#define CMD_ENGINE_FACTORY_H

#include <map>
#include "GameObject.h"

class Factory {
private:
	// Pointeur vers l'unique instance de Factory
    static Factory* instance;

	// Constructeur privé pour s'assurer qu'il n'y a qu'une seule instance de Factory
    Factory() { m_Factory = {}; }

public:
	// Fonction statique pour obtenir l'unique instance de Factory
    static Factory* getInstance();

	// Définition du type Creator qui est un pointeur vers une fonction qui crée un GameObject
    typedef GameObject* (*Creator)(Position pos, char c);

	// Table de hachage qui stocke des fonctions de création (Creators) pour chaque type d'objet
    std::map<int, Creator> m_Factory;

	// Fonction pour créer un nouvel objet de jeu à partir d'un type, d'une position et d'un caractère donnés
    GameObject* createObject(uint32_t type, Position pos, char c);

	// Fonction pour enregistrer une fonction de création (Creator) pour un type d'objet donné
    void Register(uint32_t type, Creator creator);


};


#endif
