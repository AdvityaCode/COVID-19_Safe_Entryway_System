#include "mbed.h"
#include "arm_book_lib.h"

#include "servo.h"

#include "mbed.h"

// Define pins
DigitalOut trigger(PA_7);
DigitalIn echo(PA_6);
UnbufferedSerial uartUsb(USBTX, USBRX, 115200);

void pcSerialComStringWrite( const char* str )
{
    uartUsb.write( str, strlen(str) );
}


// Function to measure distance
float measure_distance() {
    // Send trigger pulse
    trigger = 1;
    wait_us(10);
    trigger = 0;

    // Wait for echo start
    while (echo == 0);
    Timer timer;
    timer.start();

    // Wait for echo end
    while (echo == 1);
    timer.stop();

    // Calculate duration in microseconds
    float duration = timer.elapsed_time().count(); // in microseconds

    // Convert time to distance (speed of sound = 343 m/s)
    float distance_cm = (duration * 0.0343f) / 2.0f;
    
    return distance_cm;
}

int printToMon() {
    char str[100] = "";
    float distance = measure_distance();
    sprintf ( str, "Distance: %.2f cm\n", distance,
                    measure_distance() );
    pcSerialComStringWrite( str );  

}
