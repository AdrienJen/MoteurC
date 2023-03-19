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
	// Destructeur pour nettoyer la m�moire allou�e aux gameObjects
    ~Scene();

	// Fonctions virtuelles qui seront d�finies dans les classes d�riv�es pour les appels de frame
    void Start() override;

    void Update() override;

    void FixedUpdate() override;

    void LateUpdate() override;

	// Initialise les dimensions de la sc�ne
    void SetSceneDimensions(int width, int height);

	// Retourne la largeur de la sc�ne
    int getWidth() const;

	// Retourne la hauteur de la sc�ne
    int getHeight() const;

	// Instancie un nouveau GameObject dans la sc�ne
    void Instantiate(GameObject* go);

	// Retourne une liste de GameObjects qui ont le tag sp�cifi�
    std::vector<GameObject*> findObjectWithTags(int tag);

	// Retourne la liste de tous les GameObjects dans la sc�ne
    std::vector<GameObject*>& getGameObjects();
};
#endif