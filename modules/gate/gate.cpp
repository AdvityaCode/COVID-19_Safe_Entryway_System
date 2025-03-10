#include "mbed.h"
#include "arm_book_lib.h"

#include "gate.h"
#include "servo.h"
#include "sanitization_proof.h"
#include "temp_sensor.h"

DigitalOut gatee(LED3);

 void gateUpdate(){
    if (LED2 == ON){
        if (getTempF() >= 85 && getTempF() <= 99){
            gatee = ON;
            // display entry granted
            //LED2 = OFF;
        }
        else if (getTempF() > 99){
            // display entry denied
            //LED2 = OFF;
        }
    }
 }
