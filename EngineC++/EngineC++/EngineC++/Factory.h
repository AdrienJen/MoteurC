#pragma once
#ifndef CMD_ENGINE_FACTORY_H
#define CMD_ENGINE_FACTORY_H

#include <map>
#include "GameObject.h"

class Factory {
private:
	// Pointeur vers l'unique instance de Factory
    static Factory* instance;

	// Constructeur priv� pour s'assurer qu'il n'y a qu'une seule instance de Factory
    Factory() { m_Factory = {}; }

public:
	// Fonction statique pour obtenir l'unique instance de Factory
    static Factory* getInstance();

	// D�finition du type Creator qui est un pointeur vers une fonction qui cr�e un GameObject
    typedef GameObject* (*Creator)(Position pos, char c);

	// Table de hachage qui stocke des fonctions de cr�ation (Creators) pour chaque type d'objet
    std::map<int, Creator> m_Factory;

	// Fonction pour cr�er un nouvel objet de jeu � partir d'un type, d'une position et d'un caract�re donn�s
    GameObject* createObject(uint32_t type, Position pos, char c);

	// Fonction pour enregistrer une fonction de cr�ation (Creator) pour un type d'objet donn�
    void Register(uint32_t type, Creator creator);


};


#endif
