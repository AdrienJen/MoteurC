// Emp�che l'inclusion multiple du fichier d'en-t�te
#pragma once

#ifndef CMD_ENGINE_COMPONENT_H
#define CMD_ENGINE_COMPONENT_H

// Inclut le fichier d'en-t�te Object.h
#include "Object.h"
#include "Behaviour.h"
    class GameObject;
    class Component : public Object {
    public:
		// Constructeur qui prend un pointeur vers un GameObject et initialise gameObject
        explicit Component(GameObject* go) : gameObject(go) {}
		// Pointeur vers le GameObject auquel ce composant est attach�
		GameObject* gameObject;
		// Constructeur par d�faut
        Component();

		// Constante statique qui pourrait �tre utilis�e pour identifier le type de ce composant
        static const int typeHash = 0;

    };




#endif

