//=====[Libraries]=============================================================

#include "automobile_control_system.h"

//=====[Main function, the program entry point after power on or reset]========

int main()
{
    automobile_control_subsystem_Init();
    while (true) {
        automobile_control_subsystem_update();
    }
}
