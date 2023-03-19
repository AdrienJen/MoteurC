
#include "PlayerMovement.h"
#include "Input.h"
#include "KeyCode.h"
#include "Time.h"
#include "GameObject.h"


void PlayerMovement::Start() {
    transform = gameObject->getComponent<Transform>();
    if (transform == nullptr) {
        std::cerr << "PlayerMovement n'a pas trouvé de transform";
    }
}

void PlayerMovement::Update() {
    std::cout << "Position " << transform->pos.x << " , " << transform->pos.y << std::endl;

    if (Input::GetKeyDown(KeyCode::Z)) {
        transform->pos += (Position::up * Time::DeltaTime()) * speed;

    }
    if (Input::GetKeyDown(KeyCode::Q)) {
        transform->pos += Position::left * Time::DeltaTime() * speed;
        std::cout << "Position::left" << std::endl;
    }
    if (Input::GetKeyDown(KeyCode::S)) {
        transform->pos += Position::down * Time::DeltaTime() * speed;
        std::cout << "Position::down" << std::endl;
    }
    if (Input::GetKeyDown(KeyCode::D)) {
        transform->pos += Position::right * Time::DeltaTime() * speed;
        std::cout << "Position::right" << std::endl;
    }
}

void PlayerMovement::LateUpdate() {

}

void PlayerMovement::FixedUpdate() {

}
