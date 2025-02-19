//=====[Libraries]=============================================================

#include "arm_book_lib.h"

#include "automobile_control_system.h"

#include "display.h"
#include "user_interface.h"
#include "ignition_subsystem.h"
#include "servo.h"
#include "windshield_wiper_subsystem.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void automobile_control_subsystem_Init()
{
    inputsInit();
    outputsInit();
    displayInit();
}

void automobile_control_subsystem_update()
{
    engineToggle();
    uartTask();
    ledActivation();
    wiperActivation();
    displayMode();
}

//=====[Implementations of private functions]==================================
