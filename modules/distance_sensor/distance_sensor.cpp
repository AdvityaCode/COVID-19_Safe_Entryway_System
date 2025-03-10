#include "mbed.h"
#include "arm_book_lib.h"

#include "servo.h"

#include "mbed.h"
#include <cstdio>

// Define pins
DigitalOut trigger(PA_7);
DigitalIn echo(PA_6);
UnbufferedSerial uartUsb(USBTX, USBRX, 115200);

DigitalOut dispensedLED(LED1);

void pcSerialComStringWrite( const char* str )
{
    uartUsb.write( str, strlen(str) );
}

float measure_distance() {
    trigger = 1;
    wait_us(10);
    trigger = 0;

    while (echo == 0);
    Timer timer;
    timer.start();

    while (echo == 1);
    timer.stop();

    float duration = chrono::duration<float, std::micro>(timer.elapsed_time()).count();
    float distance_cm = (duration * 0.0343f) / 2.0f;
    
    return distance_cm;
}


void printToMon() {
    char str[100] = "";
    float distance = measure_distance();
    sprintf ( str, "Distance: %.2f cm\n", distance,
                    measure_distance() );
    pcSerialComStringWrite( str );  

}

void check_and_activate_motor() {
    while (measure_distance() > 7.0 && !dispensedLED){
        printToMon();
        if (measure_distance() < 7.0) {
            wiperSingleMove2();  // Move the motor
            delay(2000);
            dispensedLED = ON;
        }
    }
}

