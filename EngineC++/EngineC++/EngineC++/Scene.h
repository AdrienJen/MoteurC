#pragma once
#ifndef CMD_ENGINE_SCENE_H
#define CMD_ENGINE_SCENE_H

#include <vector>

#include "Object.h"
#include "GameObject.h"

class Scene : public Object {

    int width = 0;
    int height = 0;
    std::vector<GameObject*> gameObjects;
public:
	// Destructeur pour nettoyer la mémoire allouée aux gameObjects
    ~Scene();

	// Fonctions virtuelles qui seront définies dans les classes dérivées pour les appels de frame
    void Start() override;

    void Update() override;

    void FixedUpdate() override;

    void LateUpdate() override;

	// Initialise les dimensions de la scène
    void SetSceneDimensions(int width, int height);

	// Retourne la largeur de la scène
    int getWidth() const;

	// Retourne la hauteur de la scène
    int getHeight() const;

	// Instancie un nouveau GameObject dans la scène
    void Instantiate(GameObject* go);

	// Retourne une liste de GameObjects qui ont le tag spécifié
    std::vector<GameObject*> findObjectWithTags(int tag);

	// Retourne la liste de tous les GameObjects dans la scène
    std::vector<GameObject*>& getGameObjects();
};
#endif