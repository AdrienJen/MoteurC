// EngineC++.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "MapLoader.h"
#include "System.h"
#include "Scene.h"
#include "Factory.h"
#include "ASCIIRenderer.h"
#include "TagManager.h"
#include "PlayerMovement.h"
#include <vector>

constexpr float updateRate = 1.f / 100.f;
constexpr float fixedUpdateRate = 1.f / 100.f;

// Fonction qui crée un objet basique avec une position et un caractère ASCII à afficher
GameObject* CreateBaseObject(Position pos, char c) {
	GameObject* object = new GameObject();
	Transform* trans = new Transform(object, pos);
	ASCIIRenderer* renderer = new ASCIIRenderer(object, c, 0);

	object->AddComponent(trans);
	object->AddComponent(renderer);
	return object;
}

// Fonction qui crée un joueur (un objet basique avec des spécificités pour le joueur)
GameObject* CreatePlayer(Position pos, char c) {
	GameObject* player = CreateBaseObject(pos, c);
	player->tag = TagManager::getInstance()->m_TagManager["Player"];
	// Ajout de composants spécifiques au joueur
	PlayerMovement* pm = new PlayerMovement(player);
	player->AddComponent(pm);
	return player;
}

// Fonction qui crée un ennemi (un objet basique avec des spécificités pour l'ennemi)
GameObject* CreateEnemy(Position pos, char c) {
	GameObject* enemy = CreateBaseObject(pos, c);
	enemy->tag = TagManager::getInstance()->m_TagManager["Enemy"];

	// Ajout de composants spécifiques à l'ennemi
	return enemy;
}

// Fonction qui crée un mur (un objet basique avec des spécificités pour le mur)
GameObject* CreateWall(Position pos, char c) {
	GameObject* wall = CreateBaseObject(pos, c);
	wall->tag = TagManager::getInstance()->m_TagManager["Wall"];

	// Ajout de composants spécifiques au mur
	return wall;
}

// Fonction qui crée de l'or (un objet basique avec des spécificités pour l'or)
GameObject* CreateGold(Position pos, char c) {
	GameObject* gold = CreateBaseObject(pos, c);
	gold->tag = TagManager::getInstance()->m_TagManager["Gold"];
	// Ajout de composants spécifiques à l'or
	return gold;
}

int main() {
	TagManager* tagManager = TagManager::getInstance();
	int playerHashed = tagManager->createTag("Player"); // Création d'un tag pour le joueur
	int enemyHashed = tagManager->createTag("Enemy"); // Création d'un tag pour l'ennemi
	int wallHashed = tagManager->createTag("Wall"); // Création d'un tag pour le mur
	int goldHashed = tagManager->createTag("Gold"); // Création d'un tag pour l'or
	Factory* fac = Factory::getInstance();
	fac->Register(playerHashed, CreatePlayer); // Enregistrement de la fonction de création pour les joueurs
	fac->Register(enemyHashed, CreateEnemy); // Enregistrement de la fonction de création pour les ennemis
	fac->Register(wallHashed, CreateWall); // Enregistrement de la fonction de création pour les murs
	fac->Register(goldHashed, CreateGold); // Enregistrement de la fonction de création pour l'or

	std::cout << "Hello, World!" << std::endl; // Affiche le message "Hello, World!" sur la console

	MapLoader loader; // Crée une instance de la classe MapLoader, qui permet de charger une carte à partir d'un fichier
	std::string mapFile = "map1.txt"; // Définit le nom du fichier de la carte à charger

	std::vector<Scene*> Scenes = { // Crée un vector de pointeurs de scènes, qui va contenir toutes les scènes du jeu
			new Scene() // Ajoute une nouvelle scène au vector, initialisée avec des valeurs par défaut
	};
	loader.LoadMap(fac, Scenes[0], mapFile); // Charge la carte depuis le fichier "map1.txt" et la stocke dans la première scène du vector "Scenes"
	System app(Scenes); // Crée une instance de la classe System, qui va gérer la boucle principale du jeu en s'appuyant sur les scènes fournies
	app.Run(); // Lance la boucle principale du jeu, qui va appeler les fonctions Update(), FixedUpdate() et LateUpdate() des différents objets de la scène

	std::string str2; // Crée une variable de type string nommée "str2"
	std::cin >> str2; // Attend l'entrée utilisateur sur la console et stocke la saisie dans la variable "str2"


}



// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
