//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "ignition_subsystem.h"
#include "automobile_control_system.h"


//=====[Defines]===============================================================
#define POTENTIOMETER_OVER_TEMP_LEVEL            50
#define TIME_INCREMENT_MS

//=====[Declaration and initialization of public global objects]===============

DigitalIn driverSeat(D13);
DigitalIn passengerSeat(D12);
DigitalIn driverBelt(D11);
DigitalIn passengerBelt(D10);
DigitalIn ignitionButton(BUTTON1);

DigitalOut ignitionEnabledLED(LED1);
DigitalOut engineLED(LED2);

DigitalInOut sirenPin(PE_10);

UnbufferedSerial uartUsb(USBTX, USBRX, 115200);

//=====[Declaration and initialization of public global variables]=============

static bool welcomeCheckWait = true;

bool driverState = OFF;
bool engineState = OFF; 
bool alarmON = OFF;
bool engineON = OFF;
bool ignitionLEDState = OFF; 

//=====[Implementations of public functions]===================================

void inputsInit()
{
    driverSeat.mode(PullDown);
    passengerSeat.mode(PullDown);
    driverBelt.mode(PullDown);
    passengerBelt.mode(PullDown);
    sirenPin.mode(OpenDrain);
    sirenPin.input();
}

void outputsInit()
{
    ignitionEnabledLED = OFF;
    engineLED = OFF;
}

void engineToggle() {
    if(engineLED && !welcomeCheckWait && engineON) {
        delay(10);
        while (ignitionButton) {
            delay(10);
            if (!ignitionButton) {
                main();
            }
        }
    }
}

void ledActivation() {
    while(!engineLED) {
        //turns ignition LED on if everything is satisfied
        if ( driverSeat && passengerSeat && driverBelt && passengerBelt ) {
            ignitionEnabledLED = ON;
        }

    //if ignitionEnabledLED is ON and ignition button is pressed, turn blue led on. 
        if (ignitionEnabledLED && ignitionButton) {
            engineLED = ON;
            engineState = ON;
            ignitionEnabledLED = OFF;
            ignitionLEDState = ON;
            delay(300);
        }

    //if engineLED is on, turn this variable around
        if (engineLED){
            engineON = ON; 
            ignitionLEDState = ON;
            sirenPin.input(); 
        }

    //if both LEDs are off and ignition button is pushed, turn buzzer on. 
        if (!ignitionEnabledLED && ignitionButton && alarmON == OFF && !ignitionLEDState) {
            sirenPin.output();
            sirenPin = LOW;
            alarmON = ON;
            
            uartUsb.write("Ignition inhibited\r\n", 20);

            if (driverSeat == OFF) {
                uartUsb.write("Driver seat is not occupied\r\n", 30);
            }

            if (passengerSeat == OFF) {
                uartUsb.write("Passenger seat is not occupied\r\n", 32);
            }

            if (driverBelt == OFF) {
                uartUsb.write("Driver belt is not fastened\r\n", 30);
            }

            if (passengerBelt == OFF) {
                uartUsb.write("Passenger belt is not fastened\r\n", 32);
            }
            uartUsb.write("Try again!\r\n", 12);
        }
    }
}

void uartTask(){
    while (welcomeCheckWait){
        if ( driverState == OFF && driverSeat ) {
            driverState = ON; 
            uartUsb.write( "Welcome to enhanced alarm system model 218-W24\r\n", 48 );
            welcomeCheckWait = !welcomeCheckWait;
        }	
    }    

    if (ignitionEnabledLED == OFF && engineState ){
        engineState = OFF; 
        uartUsb.write( "Engine started\r\n", 16 );
    }

}




