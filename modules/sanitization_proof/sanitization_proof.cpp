#include "mbed.h"
#include "arm_book_lib.h"
#include "gas_sensor.h"
#include "user_interface.h"

DigitalOut SanitizationProved(LED2);
bool sanitizerProved = false;

void sanitizationProofUpdate(){
    if (!gasSensorRead()) {
        SanitizationProved = ON;
        sanitizerProved = true;
        displayCheckTemp();
    }
}

bool returnSanitized() {
    return sanitizerProved;
}