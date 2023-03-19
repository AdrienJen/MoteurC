#pragma once
#ifndef CMD_ENGINE_GAMEOBJECT_H
#define CMD_ENGINE_GAMEOBJECT_H

#include "Object.h"
#include "Component.h"
#include "Transform.h"
#include <utility>
#include <vector>
#include <cassert>
class GameObject : public Object {
protected:
	// Vecteur de pointeurs vers des Component
	std::vector<Component*> components;
public:
	// Tag d'instance et tag de l'objet
	int instanceTag;
	int tag = 0;

	// Constructeurs et destructeur de GameObject
	GameObject();
	GameObject(std::vector<Component*> nc);
	//GameObject(std::unique_ptr<Transform> nt);

	GameObject(GameObject& go);

	~GameObject();

	// Fonctions virtuelles de la classe Object
	void Start() override;

	void Update() override;

	void FixedUpdate() override;

	void LateUpdate() override;

	// Fonction template qui renvoie un pointeur vers un Component du type T
	template<class T>
	T* getComponent() {
		// Vérifie que le type T dérive de Component
		static_assert(std::is_base_of<Component, T>::value, "type parameter of this class must derive from Component");
		// Parcours le vecteur de Component
		for (Component* c : components) {
			
			// Vérifie que le Component est du type T
			T* casted = dynamic_cast<T*>(c);
			if (casted != nullptr) {
				// Vérifie que le typeHash de T correspond à celui du Component
				assert(T::typeHash == casted->typeHash);
				return casted;
			}
		}
		// Aucun Component du type T n'a été trouvé, on retourne nullptr
		return nullptr;
	}
	// Fonction qui ajoute un Component au GameObject
	void AddComponent(Component* comp);
};


#endif