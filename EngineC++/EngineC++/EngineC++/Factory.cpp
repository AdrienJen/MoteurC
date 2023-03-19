#include "Factory.h"

// Initialisation du pointeur d'instance
Factory* Factory::instance = 0;

// Récupération de l'instance unique de la Factory
Factory* Factory::getInstance() {
	// Utilisation du design pattern Singleton pour s'assurer qu'il n'y ait qu'une seule instance de la classe à tout moment
	if (!instance)
        instance = new Factory;
	std::cout << "Test" << std::endl; 
    return instance;
}

// Création d'un objet en fonction de son type
GameObject* Factory::createObject(uint32_t type, Position pos, char c) {
	// Utilisation d'un tableau de pointeurs de fonctions membres de la classe Factory
	// qui permettent de créer des objets de différents types en fonction du type d'objet demandé
	return m_Factory[type](pos, c);
}

// Enregistrement d'un nouveau type d'objet dans la factory
void Factory::Register(uint32_t type, Factory::Creator creator) {
    m_Factory.insert(std::pair<uint32_t, Creator>(type, creator));
}

