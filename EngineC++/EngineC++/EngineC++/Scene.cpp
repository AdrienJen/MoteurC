#include "Scene.h"
#include "TagManager.h"

void Scene::Start() {
	// Boucle à travers tous les GameObjects dans la scène et appelle leur méthode Start()
	for (GameObject* go : gameObjects) {
		go->Start();
	}
	// Cherche tous les GameObjects avec le tag "Player" et les stocke dans un vecteur
	std::vector<GameObject*> player = findObjectWithTags(TagManager::getInstance()->m_TagManager["Player"]);
}

void Scene::Update() {
	// Boucle à travers tous les GameObjects dans la scène et appelle leur méthode Update()
	for (GameObject* go : gameObjects) {
		go->Update();
	}
}

void Scene::FixedUpdate() {
	// Boucle à travers tous les GameObjects dans la scène et appelle leur méthode FixedUpdate()
	for (GameObject* go : gameObjects) {
		go->FixedUpdate();
	}
}

void Scene::LateUpdate() {
	// Boucle à travers tous les GameObjects dans la scène et appelle leur méthode LateUpdate()
	for (GameObject* go : gameObjects) {
		go->LateUpdate();
	}
}

Scene::~Scene() {
	// Boucle à travers tous les GameObjects dans la scène et ne fait rien
	// Cette méthode pourrait être utilisée pour libérer de la mémoire associée aux GameObjects, mais ce n'est pas implémenté ici
	for (GameObject* go : gameObjects) {

	}
}

void Scene::SetSceneDimensions(int width, int height) {
	// Définit les dimensions de la scène
	this->width = width;
	this->height = height;
}

void Scene::Instantiate(GameObject* go) {
	// Ajoute un GameObject à la scène
	gameObjects.push_back(go);
}

int Scene::getWidth() const {
	// Retourne la largeur de la scène
	return width;
}

int Scene::getHeight() const {
	// Retourne la hauteur de la scène
	return height;
}

std::vector<GameObject*> Scene::findObjectWithTags(int searchTag) {
	// Recherche tous les GameObjects ayant le tag spécifié et les stocke dans un vecteur
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
	// Retourne une référence au vecteur de GameObjects de la scène
	return gameObjects;
}