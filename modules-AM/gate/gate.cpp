#include "mbed.h"
#include "arm_book_lib.h"

#include "gate.h"
#include "servo.h"
#include "sanitization_proof.h"
#include "temp_sensor.h"

#define LDR_THRESHOLD       0.45

DigitalOut gatee(LED3);
UnbufferedSerial gateDebug(USBTX, USBRX, 115200);

AnalogIn LDRSensor(A0);

float tempCheck;
char debugString[100];
int debugStringLength;

bool gateOpened = false;

void gateInit() {
    temp_sensor_init();
}

 void gateUpdate(){
     temp_sensor_update();
    //gateDebug.write("GATE MOMENT\n", 12);
    if (returnSanitized()){

        /*tempCheck = getTempF();
        sprintf(debugString, "checking temp attempt: %0.2f\n", tempCheck);
        debugStringLength = strlen(debugString);
        gateDebug.write(debugString, debugStringLength);*/

        if (getTempF() >= 85 && getTempF() <= 99){
            gatee = ON;
            gateServoOpen();
            gateOpened = true;
            // display entry granted
            //LED2 = OFF;
        }
        else if (getTempF() > 99){
            // display entry denied
            //LED2 = OFF;
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
