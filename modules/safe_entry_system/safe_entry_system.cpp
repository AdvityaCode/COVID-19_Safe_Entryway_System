//=====[Libraries]=============================================================

#include "arm_book_lib.h"

#include "safe_entry_system.h"

//#include "display.h"
#include "dispenser.h"
#include "gate.h"
#include "sanitization_proof.h"
//#include "distance_sensor.h"
//#include "servo.h"
#include "user_interface.h"

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
    inputsInit();
    outputsInit();
    gateInit();
    userInterfaceInit();
    //gateServoClose();
    //displayWelcome();
}

void safe_entry_system_update()
{
    dispenser_update();
    sanitizationProofUpdate();
    gateUpdate();
}

//=====[Implementations of private functions]==================================
