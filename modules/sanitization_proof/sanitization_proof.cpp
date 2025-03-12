#include "mbed.h"
#include "arm_book_lib.h"
#include "gas_sensor.h"
#include "user_interface.h"

DigitalOut SanitizationProved(LED2);
bool sanitizerProved = false;

// Sets sanitizer proved to true when the user activates the gas sensor
void sanitizationProofUpdate(){
    if (!gasSensorRead()) {
        SanitizationProved = ON;
        sanitizerProved = true;
        displayCheckTemp();
    }
}

// Returns sanitizer proved to activate the temperature check sequence in the gate module
bool returnSanitized() {
    return sanitizerProved;
}