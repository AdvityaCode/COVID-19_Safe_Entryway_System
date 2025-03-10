#include "mbed.h"
#include "arm_book_lib.h"
#include "gas_sensor.h"

DigitalOut SanitizationProved(LED2);

void sanitizationProofUpdate(){
    if (!gasSensorRead()) {
        SanitizationProved = ON;
    }
}

