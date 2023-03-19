#include "Transform.h"
void Transform::SetPosition(float nx, float ny) {
    pos.x = nx;
    pos.y = ny;
}

Position Transform::GetPosition() {
    return pos;
}

void Transform::SetPosition(Position& np) {
    pos = np;
}

void Transform::SetPosition(Transform& nt) {
    pos = nt.pos;
}

Transform::~Transform() {
    delete this;
}

void Transform::Start() {

}

void Transform::Update() {

}

void Transform::FixedUpdate() {

}

void Transform::LateUpdate() {

}