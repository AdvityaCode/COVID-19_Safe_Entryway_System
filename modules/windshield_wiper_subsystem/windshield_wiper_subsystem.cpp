#include "mbed.h"
#include "arm_book_lib.h"

#include "windshield_wiper_subsystem.h"
#include "servo.h"
#include "display.h"
#include "user_interface.h"

AnalogIn modeSelector(A0);
AnalogIn INTmodeSelector(A1);
float modeReading = 0.0;
float INTmodeReading = 0.0;


void wiperActivation(){
    modeReading = modeSelector.read();
    if (modeReading<0.25) {
        wiperHigh();
    }

    if (modeReading>=0.25 && modeReading<0.5) {
        wiperLow();
    }

    if (modeReading>=0.5 && modeReading<0.75) {
        wiperOff();
    }

    if (modeReading>=0.75) {
        wiperINTActivation();
    }

}

void wiperINTActivation(){
    INTmodeReading = INTmodeSelector.read();
    
    if (modeReading>=0.75 && INTmodeReading<0.33) {
        wiperThree();
    }

    if (modeReading>=0.75 && INTmodeReading>=0.33 && INTmodeReading<0.66) {
        wiperSix();
    }

    if (modeReading>=0.75 && INTmodeReading>=0.66) {
        wiperEight();
    }
}

void displayMode(){
    modeReading = modeSelector.read();
    displayInit();
    if (modeReading<0.25) {
        displayHigh();
    }

    if (modeReading>=0.25 && modeReading<0.5) {
        displayLow();
    }

    if (modeReading>=0.5 && modeReading<0.75) {
        displayOff();
    }

    if (modeReading>=0.75) {
        displayINTMode();
    }
}

void displayINTMode(){
    INTmodeReading = INTmodeSelector.read();
    displayInit();
    if (INTmodeReading<0.33) {
        displayInt3();
    }

    if (INTmodeReading>=0.33 && INTmodeReading<0.66) {
        displayInt6();
    }

    if (INTmodeReading>=0.66) {
        displayInt8();
    }

}

