#include "mbed.h"
#include "arm_book_lib.h"
#include "gas_sensor.h"

DigitalOut SanitizationProved(LED2);
bool sanitizationProved = false;

void sanitizationProofUpdate(){
    if (gasSensorRead()) {
        SanitizationProved = ON;
        sanitizationProved = true;
    }
}

bool returnSanitized() {
    return sanitizationProved;
}