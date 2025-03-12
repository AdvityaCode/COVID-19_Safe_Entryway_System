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

float tempCheck;
char debugString[100];
int debugStringLength;

bool gateOpened = false;

void gateInit() {
    temp_sensor_init();
    gateServoClose();
}

 void gateUpdate(){
    temp_sensor_update();
    //gateDebug.write("GATE MOMENT\n", 12);
    if (returnSanitized()){

        if (!gateOpened) {
            tempCheck = getTempF();
            sprintf(debugString, "checking temp attempt: %0.2f\n", tempCheck);
            debugStringLength = strlen(debugString);
            gateDebug.write(debugString, debugStringLength);
        } else {
            sprintf(debugString, "checking light: %0.2f\n", LDRSensor.read());
            debugStringLength = strlen(debugString);
            gateDebug.write(debugString, debugStringLength);
        }


        if (getTempF() >= LOW_TEMP && getTempF() <= HIGH_TEMP){
            gatee = ON;
            entryGranted();
            gateServoOpen();
            gateOpened = true;
        }
        else if (getTempF() > HIGH_TEMP){
            entryDeniedTemp();
        }

        /*sprintf(debugString, "LDR: %0.2f\n", LDRSensor.read());
        debugStringLength = strlen(debugString);
        gateDebug.write(debugString, debugStringLength);*/

        if (gateOpened == true && LDRSensor.read() > LDR_THRESHOLD) {
            gateOpened = false;
            gateServoClose();
        }
    }


 }
