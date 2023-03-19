#include "System.h"
#include "Time.h"
#include "ASCIIRenderer.h"
#include "Input.h"
#include "KeyCode.h"
#include <string>

void System::Run() {
	// Appelle la m�thode Start pour lancer le jeu
	Start();


	// Boucle principale du jeu
	while (isPlaying) {

		InternalUpdate();
		Time::Update();
	}
	// Supprime le syst�me une fois le jeu termin�
	//delete this;
}

System::~System() {
	// Supprime la sc�ne s�lectionn�e
	delete Scenes[selectedScene];
}

void System::InternalUpdate() {
	// Met � jour le temps �coul� depuis la derni�re frame
	timeAcu += Time::DeltaTime();

	// Tant que le temps accumul� d�passe le temps de mise � jour fixe et qu'on n'a pas atteint le nombre maximal de boucles
	while (timeAcu >= updateRate && loop < MAX_LOOP) {
		FixedUpdate();
		timeAcu -= updateRate;
		++loop;
	}
	loop = 0;

	// Met � jour la logique du jeu pour la frame actuelle
	Update();
	// Appelle la m�thode LateUpdate de la sc�ne s�lectionn�e
	LateUpdate();
}

void System::LateUpdate() {
	// R�cup�re la sc�ne s�lectionn�e
	Scene* s = Scenes[selectedScene];
	// Appelle la m�thode LateUpdate de la sc�ne
	s->LateUpdate();

	// Efface l'�cran si l'option clear_frame est activ�e
	if (clear_frame)
		std::system("cls");

	// Rasterisation ASCII : r�cup�re les objets de la sc�ne et les affiche en ASCII sur l'�cran
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

	// Rendu final : affiche la matrice ASCII sur l'�cran
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