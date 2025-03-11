//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "dispenser.h"
#include "servo.h"
#include "distance_sensor.h"
#include "display.h"

//=====[Defines]===============================================================

float handDistance;

//=====[Declaration and initialization of public global objects]===============


//=====[Declaration and initialization of public global variables]=============


//=====[Implementations of public functions]===================================

void inputsInit(){
    servoInit();
    displayInit();
}

void outputsInit()
{
}

void dispenser_update(){
    check_and_activate_motor();
}

