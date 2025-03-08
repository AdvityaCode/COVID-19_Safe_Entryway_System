//=====[Libraries]=============================================================

#include "arm_book_lib.h"

#include "safe_entry_system.h"

#include "display.h"
#include "dispenser.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void safe_entry_system_init()
{
    diplayWelcome();
    inputsInit();
    outputsInit();
    displayInit();
}

void safe_entry_system_update()
{
    uartTask();
    ledActivation();
    wiperActivation();
    displayMode();
}

//=====[Implementations of private functions]==================================
