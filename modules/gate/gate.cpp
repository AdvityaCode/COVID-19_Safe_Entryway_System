#include "mbed.h"
#include "arm_book_lib.h"

#include "gate.h"
#include "servo.h"
#include "sanitization_proof.h"
#include "temp_sensor.h"
#include "user_interface.h"

#define LDR_THRESHOLD       0.45
#define LOW_TEMP            90
#define HIGH_TEMP           99

DigitalOut gatee(LED3);
UnbufferedSerial gateDebug(USBTX, USBRX, 115200);

AnalogIn LDRSensor(A0);

// Variables for debugging
float tempCheck;
char debugString[100];

bool gateOpened = false;

// Initializes the temperature sensor and closes the gate
void gateInit() {
    temp_sensor_init();
    gateServoClose();
}

 void gateUpdate(){
    temp_sensor_update();
    if (returnSanitized()){

        /* These lines of code are for debugging: Displays temperature or light level before and after gate opens respectively
        if (!gateOpened) {
            tempCheck = getTempAvg();
            sprintf(debugString, "checking temp attempt: %0.2f\n", tempCheck);
            gateDebug.write(debugString, strlen(debugString));
        } else {
            sprintf(debugString, "checking light: %0.2f\n", LDRSensor.read());
            gateDebug.write(debugString, strlen(debugString));
        }*/

        // Opens the gate and grants entry when the user is healthy temp, denies user if fever
        if (getTempAvg() >= LOW_TEMP && getTempAvg() <= HIGH_TEMP){
            gatee = ON;
            entryGranted();
            gateServoOpen();
            gateOpened = true;
        }
        else if (getTempAvg() > HIGH_TEMP){
            entryDeniedTemp();
        }

        /*sprintf(debugString, "LDR: %0.2f\n", LDRSensor.read());
        debugStringLength = strlen(debugString);
        gateDebug.write(debugString, debugStringLength);*/

        // Closes the gate when the LDR sensor reads low
        if (gateOpened == true && LDRSensor.read() > LDR_THRESHOLD) {
            gateOpened = false;
            gateServoClose();
        }
    }


 }
