#pragma once
#ifndef CMD_ENGINE_PLAYERMOVEMENT_H
#define CMD_ENGINE_PLAYERMOVEMENT_H

#include "Component.h"
#include "Transform.h"

class PlayerMovement : public Component {
protected:
    Transform* transform;
    float speed = 1000;
public:
    PlayerMovement(GameObject* go) : Component(go) {}
    void Start() override;

    void Update() override;

    void LateUpdate() override;

    void FixedUpdate() override;
};


#endif
