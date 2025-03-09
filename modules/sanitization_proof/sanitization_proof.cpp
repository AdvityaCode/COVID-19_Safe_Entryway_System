#include "mbed.h"
#include "arm_book_lib.h"

AnalogIn gasSensor(A0);
DigitalOut SanitizationProved(LED1);

#define SANITIZED_THRESHOLD 0.4f
UnbufferedSerial uartUsb(USBTX, USBRX, 115200);

void pcSerialComStringWrite( const char* str )
{
    uartUsb.write( str, strlen(str) );
}

float sanitizationProofUpdate(){

    while (true) {
        float sensorValue = gasSensor.read();  // Read analog value (0.0 - 1.0)

        if (sensorValue > SANITIZED_THRESHOLD) {
            SanitizationProved = 1;  // Turn on LED when sanitized air is detected
        } else {
            SanitizationProved = 0;  // Turn off LED otherwise
        }

        ThisThread::sleep_for(500ms);
    return sensorValue;
    }
}

void printToMon2() {
    char str[100] = "";
    float gasStatus = gasSensor.read();
    sprintf ( str, "Distance: %.2f cm\n", gasStatus,
                    sanitizationProofUpdate());
    pcSerialComStringWrite( str );  

}
