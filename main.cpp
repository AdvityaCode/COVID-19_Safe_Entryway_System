//=====[Libraries]=============================================================

#include "safe_entry_system.h"
#include "dispenser.h"
#include "servo.h"
#include "distance_sensor.h"
#include "sanitization_proof.h"

//=====[Main function, the program entry point after power on or reset]========

int main() 
{
//    safe_entry_system_init();   
    while (true) {
//        dispenser_update();
        sanitizationProofUpdate();
    }
}