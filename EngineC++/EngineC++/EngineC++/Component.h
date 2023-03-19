// Empêche l'inclusion multiple du fichier d'en-tête
#pragma once

#ifndef CMD_ENGINE_COMPONENT_H
#define CMD_ENGINE_COMPONENT_H

// Inclut le fichier d'en-tête Object.h
#include "Object.h"
#include "Behaviour.h"
    class GameObject;
    class Component : public Object {
    public:
		// Constructeur qui prend un pointeur vers un GameObject et initialise gameObject
        explicit Component(GameObject* go) : gameObject(go) {}
		// Pointeur vers le GameObject auquel ce composant est attaché
		GameObject* gameObject;
		// Constructeur par défaut
        Component();

		// Constante statique qui pourrait être utilisée pour identifier le type de ce composant
        static const int typeHash = 0;

    };




#endif

