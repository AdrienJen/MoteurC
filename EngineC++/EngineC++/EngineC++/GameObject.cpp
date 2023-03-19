#include "GameObject.h"
#include "GameObject.h"

/*GameObject::GameObject(std::unique_ptr<Transform> nt) {
    components.push_back(std::move(nt));
}*/


GameObject::GameObject() {

}

GameObject::~GameObject() {
    for (Component* c : components) {
        //delete c;
    }
}

void GameObject::Start() {
    for (Component* c : components) {
        c->Start();
    }
}

void GameObject::Update() {
    for (Component* c : components) {
        c->Update();
    }
}

void GameObject::FixedUpdate() {
    for (Component* c : components) {
        c->FixedUpdate();
    }
}

void GameObject::LateUpdate() {
    for (Component* c : components) {
        c->LateUpdate();
    }
}

GameObject::GameObject(std::vector<Component*> nc) {
    components = std::move(nc);
}

void GameObject::AddComponent(Component* comp) {
    components.push_back(comp);
}

GameObject::GameObject(GameObject& go) {
    this->components = go.components;
}
