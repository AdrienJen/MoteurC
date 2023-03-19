#pragma once
#ifndef CMD_ENGINE_INPUT_H
#define CMD_ENGINE_INPUT_H

#include "KeyCode.h"
#include <conio.h>

class Input {
public:
    static bool GetKeyDown(KeyCode keyCode);
};


#endif