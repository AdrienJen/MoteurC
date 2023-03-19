#pragma once
#ifndef CMD_ENGINE_TRANSFORM_H
#define CMD_ENGINE_TRANSFORM_H

#include "Component.h"
#include "Position.h"

// Classe Transform héritant de Component
class Transform : public Component {
public:
	// Position du transform
	Position pos;

	// Constructeurs
	Transform(GameObject* go) : Component(go), pos() {}
	Transform(GameObject* go, float nx, float ny) : Component(go), pos(nx, ny) {}
	Transform(GameObject* go, Position& np) : Component(go), pos(np) {}
	Transform(GameObject* go, Transform& nt) : Component(go), pos(nt.GetPosition()) {}

	// Destructeur
	~Transform();

	// Getters et setters pour la position
	Position GetPosition();
	void SetPosition(float nx, float ny);
	void SetPosition(Position& np);
	void SetPosition(Transform& nt);

	// Implémentation des méthodes virtuelles héritées de Component
	void Start() override;
	void Update() override;
	void FixedUpdate() override;
	void LateUpdate() override;

	// Hashage du type pour identifier les composants de type Transform
	static const int typeHash = 1;
};

#endif