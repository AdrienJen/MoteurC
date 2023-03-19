#include "System.h"
#include "Time.h"
#include "ASCIIRenderer.h"
#include "Input.h"
#include "KeyCode.h"
#include <string>

void System::Run() {
	// Appelle la méthode Start pour lancer le jeu
	Start();


	// Boucle principale du jeu
	while (isPlaying) {

		InternalUpdate();
		Time::Update();
	}
	// Supprime le système une fois le jeu terminé
	//delete this;
}

System::~System() {
	// Supprime la scène sélectionnée
	delete Scenes[selectedScene];
}

void System::InternalUpdate() {
	// Met à jour le temps écoulé depuis la dernière frame
	timeAcu += Time::DeltaTime();

	// Tant que le temps accumulé dépasse le temps de mise à jour fixe et qu'on n'a pas atteint le nombre maximal de boucles
	while (timeAcu >= updateRate && loop < MAX_LOOP) {
		FixedUpdate();
		timeAcu -= updateRate;
		++loop;
	}
	loop = 0;

	// Met à jour la logique du jeu pour la frame actuelle
	Update();
	// Appelle la méthode LateUpdate de la scène sélectionnée
	LateUpdate();
}

void System::LateUpdate() {
	// Récupère la scène sélectionnée
	Scene* s = Scenes[selectedScene];
	// Appelle la méthode LateUpdate de la scène
	s->LateUpdate();

	// Efface l'écran si l'option clear_frame est activée
	if (clear_frame)
		std::system("cls");

	// Rasterisation ASCII : récupère les objets de la scène et les affiche en ASCII sur l'écran
	int width = s->getWidth();
	int height = s->getHeight();

	std::vector<std::string> map;
	for (int i = 0; i < height; i++) {
		std::string line = "";
		for (int j = 0; j < width; j++) {
			line += ".";
		}
		map.push_back(line);
	}

	for (GameObject* go : s->getGameObjects()) {
		Transform* transform = go->getComponent<Transform>();
		ASCIIRenderer* renderer = go->getComponent<ASCIIRenderer>();
		int x = (int)transform->pos.x;
		int y = (int)transform->pos.y;

		map[y][x] = renderer->getAsciiValue();
	}

	// Rendu final : affiche la matrice ASCII sur l'écran
	std::string render = "";
	for (int i = 0; i < map.size(); i++) {
		render += map[i] + "\n";
	}
	std::cout << render << std::endl;

	frameCounter++;
	//	if(frameCounter > 1000) isPlaying = false;
}

void System::Start() {
	Time::Start();
	Scenes[selectedScene]->Start();
}

void System::Update() {
	Scenes[selectedScene]->Update();
}

void System::FixedUpdate() {
	Scenes[selectedScene]->LateUpdate();
	Time::FixedUpdate();
}