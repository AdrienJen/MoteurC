#pragma once
#ifndef CMD_ENGINE_SYSTEM_H
#define CMD_ENGINE_SYSTEM_H

#include <utility>
#include <vector>
#include "Object.h"
#include "Scene.h"

struct System {
private:
	// Variables pour gérer la boucle de jeu
    bool clear_frame = true;// Si true, efface l'affichage avant de dessiner la nouvelle frame
    //    bool needStart = false;
    bool isPlaying = true;// Si true, le jeu continue de tourner

	// Les scènes que le système doit gérer
    std::vector<Scene*> Scenes;

	// L'indice de la scène sélectionnée
    int selectedScene = 0;

    int frameCounter = 0;// Compteur de frames
    static const int MAX_LOOP = 5;// Nombre maximal de loops pour éviter que le jeu ne se bloque
    int loop = 0;// Compteur de loops
    float timeAcu = 0;// Temps écoulé depuis le dernier Update
    float FixedAcu = 0;// Temps écoulé depuis le dernier FixedUpdate
    static constexpr float updateRate = 1.f / 144.f;// Temps entre chaque Update
    static constexpr float fixedUpdateRate = 1.f / 30.f;// Temps entre chaque FixedUpdate

public:
	// Constructeur du système avec les scènes à gérer
    inline System(const std::vector<Scene*>& s) : Scenes(s) {}

    void Run();
	// Fonction interne pour gérer la boucle de jeu
    void InternalUpdate();

    void Start();

    void Update();

    void FixedUpdate();

    void LateUpdate();

	// Destructeur du système
    ~System();
};


#endif