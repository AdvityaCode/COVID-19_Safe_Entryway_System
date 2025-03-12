#include "mbed.h"
#include "arm_book_lib.h"

#include "servo.h"
#include "user_interface.h"

#include "mbed.h"
#include <cstdio>

#define DISPENSE_ACTIVATE   7.0

// Define pins
DigitalOut trigger(PA_5);
DigitalIn echo(PA_6);
UnbufferedSerial distanceSensorDebug(USBTX, USBRX, 115200);

DigitalOut dispensedLED(LED1);

// Writes to the serial montitor for debugging purposes
void pcSerialComStringWrite( const char* str )
{
    distanceSensorDebug.write( str, strlen(str) );
}

// Measures the distance of an object from the front of the distance sensor
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

// Prints distance to serial display for debugging purposes
void printToMon() {
    char str[100] = "";
    float distance = measure_distance();
    sprintf ( str, "Distance: %.2f cm\n", distance, measure_distance());
    pcSerialComStringWrite( str );  

}

// Dispenses hand sanitizer when a hand is waved within DISPENSE_ACTIVATE cm of the distance sensor
void check_and_activate_motor() {
    while (measure_distance() > DISPENSE_ACTIVATE && !dispensedLED){
        printToMon(); // Prints distance to display for debugging purposes
        if (measure_distance() < DISPENSE_ACTIVATE) {
            sanitizerServoDispense();  // Move the motor to dispense the sanitizer
            displaySantized();
            dispensedLED = ON;
        }
    }
}

