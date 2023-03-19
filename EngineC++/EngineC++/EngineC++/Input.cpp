#include "Input.h"
#include "Input.h"

#include <chrono>
#include <thread>
using std::this_thread::sleep_for;

bool Input::GetKeyDown(KeyCode keyCode) {

    sleep_for(std::chrono::milliseconds(100));
    if (_kbhit()) {
        int ch = _getch();
        if (ch == keyCode)
            return true;
    }
    return false;
}