#include "Scene.h"
#include "TagManager.h"

void Scene::Start() {
	// Boucle � travers tous les GameObjects dans la sc�ne et appelle leur m�thode Start()
	for (GameObject* go : gameObjects) {
		go->Start();
	}
	// Cherche tous les GameObjects avec le tag "Player" et les stocke dans un vecteur
	std::vector<GameObject*> player = findObjectWithTags(TagManager::getInstance()->m_TagManager["Player"]);
}

void Scene::Update() {
	// Boucle � travers tous les GameObjects dans la sc�ne et appelle leur m�thode Update()
	for (GameObject* go : gameObjects) {
		go->Update();
	}
}

void Scene::FixedUpdate() {
	// Boucle � travers tous les GameObjects dans la sc�ne et appelle leur m�thode FixedUpdate()
	for (GameObject* go : gameObjects) {
		go->FixedUpdate();
	}
}

void Scene::LateUpdate() {
	// Boucle � travers tous les GameObjects dans la sc�ne et appelle leur m�thode LateUpdate()
	for (GameObject* go : gameObjects) {
		go->LateUpdate();
	}
}

Scene::~Scene() {
	// Boucle � travers tous les GameObjects dans la sc�ne et ne fait rien
	// Cette m�thode pourrait �tre utilis�e pour lib�rer de la m�moire associ�e aux GameObjects, mais ce n'est pas impl�ment� ici
	for (GameObject* go : gameObjects) {

	}
}

void Scene::SetSceneDimensions(int width, int height) {
	// D�finit les dimensions de la sc�ne
	this->width = width;
	this->height = height;
}

void Scene::Instantiate(GameObject* go) {
	// Ajoute un GameObject � la sc�ne
	gameObjects.push_back(go);
}

int Scene::getWidth() const {
	// Retourne la largeur de la sc�ne
	return width;
}

int Scene::getHeight() const {
	// Retourne la hauteur de la sc�ne
	return height;
}

std::vector<GameObject*> Scene::findObjectWithTags(int searchTag) {
	// Recherche tous les GameObjects ayant le tag sp�cifi� et les stocke dans un vecteur
	std::vector<GameObject*> taggedObjects;
	int size = gameObjects.size();
	for (int i = 0; i < size; ++i) {
		if (gameObjects[i]->tag == searchTag) {
			taggedObjects.push_back(gameObjects[i]);
		}
	}
	return taggedObjects;
}

std::vector<GameObject*>& Scene::getGameObjects() {
	// Retourne une r�f�rence au vecteur de GameObjects de la sc�ne
	return gameObjects;
}